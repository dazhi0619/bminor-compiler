%{
#include "include/token.h"
#include "include/parser.h"
#include "include/ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int parser_result;
extern char* yytext;
extern int yylex();
extern FILE* yyin;

int yyerror(char* s);

int parser_result = 0;

struct decl* root = 0;
%}

%union {
  struct decl* decl;
  struct stmt* stmt;
  struct expr* expr;
  struct type* type;
  struct param_list* param_list;
  struct symbol* symbol;
  char* string;
  char character;
  int integer;
  double floating;
}

%type <decl> program decl
%type <stmt> block optfuncinit stmt innerstmt
%type <expr> optinit arrliteral arrliterallst exprlst arrlst optexpr expr rightval or_operand and_operand compared term exponent factor value optarrvalue multiplier
%type <type> type simpletype arrtype functype paramtype arrparam
%type <param_list> paramlist optparam

/* types */
%token TOKEN_INT
%token TOKEN_FLOAT
%token TOKEN_CHAR
%token TOKEN_STRING
%token TOKEN_ARRAY
%token TOKEN_AUTO
%token TOKEN_BOOL
%token TOKEN_TRUE
%token TOKEN_FALSE
%token TOKEN_VOID

/* statement */
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_WHILE

/* operator */
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACKET
%token TOKEN_RBRACKET

%token TOKEN_INCRE
%token TOKEN_DECRE
%token TOKEN_NOT
%token TOKEN_EXP
%token TOKEN_MINUS
%token TOKEN_DIV
%token TOKEN_MOD
%token TOKEN_PLUS
%token TOKEN_MUL
%token TOKEN_LT
%token TOKEN_LE
%token TOKEN_GT
%token TOKEN_GE
%token TOKEN_EQ
%token TOKEN_NE
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_ASSIGN

/* delimiter */
%token TOKEN_LBRACE
%token TOKEN_RBRACE
%token TOKEN_SEMI
%token TOKEN_COMMA
%token TOKEN_COLON

/* literals */
%token <integer>   TOKEN_INT_LITERAL
%token <floating>  TOKEN_FLOAT_LITERAL
%token <string>    TOKEN_STRING_LITERAL
%token <character> TOKEN_CHAR_LITERAL

/* identifier */
%token <string> TOKEN_IDENT

%%

program : decl program      { $1->next = $2; root = $1; }
        |                   { $$ = NULL; root = NULL; }
        ;

decl : TOKEN_IDENT TOKEN_COLON type optinit   { $$ = decl_create($1, $3, $4, NULL, NULL, NULL); }
     | TOKEN_IDENT TOKEN_COLON TOKEN_FUNCTION functype optfuncinit  { $$ = decl_create($1, $4, NULL, $5, NULL, NULL); }
     ;

optinit : TOKEN_ASSIGN expr TOKEN_SEMI        { $$ = $2; }
        | TOKEN_ASSIGN arrliteral TOKEN_SEMI  { $$ = $2; }
        | TOKEN_SEMI                          { $$ = NULL; }
        ;

arrliteral : TOKEN_LBRACE expr exprlst TOKEN_RBRACE              { struct expr* head = expr_create(EXPR_LIST, $2, $3); $$ = expr_create(EXPR_LIST, NULL, head); }
           | TOKEN_LBRACE arrliteral arrliterallst TOKEN_RBRACE  { struct expr* head = expr_create(EXPR_LIST, $2, $3); $$ = expr_create(EXPR_LIST, NULL, head); }
           ;

arrliterallst : TOKEN_COMMA arrliteral arrliterallst  { $$ = expr_create(EXPR_LIST, $2, $3); }
              |      { $$ = NULL; }
              ;

block: stmt block  { $1->next = $2; $$ = $1; }
     |  { $$ = NULL; }
     ;

type : simpletype  { $$ = $1; }
     | arrtype     { $$ = $1; }
     ;

simpletype : TOKEN_INT  { $$ = type_create(TYPE_INTEGER, NULL, NULL); }
     | TOKEN_FLOAT      { $$ = type_create(TYPE_FLOAT, NULL, NULL); }
     | TOKEN_STRING     { $$ = type_create(TYPE_STRING, NULL, NULL); }
     | TOKEN_CHAR       { $$ = type_create(TYPE_CHARACTER, NULL, NULL); }
     | TOKEN_BOOL       { $$ = type_create(TYPE_BOOLEAN, NULL, NULL); }
     | TOKEN_AUTO       { $$ = type_create(TYPE_VOID, NULL, NULL); }
     | TOKEN_VOID       { $$ = type_create(TYPE_VOID, NULL, NULL); }
     ;

arrtype   : TOKEN_ARRAY TOKEN_LBRACKET optexpr TOKEN_RBRACKET type  { $$ = type_create(TYPE_ARRAY, $5, NULL); $$->arr_len = $3; };

functype  : type TOKEN_LPAREN paramlist TOKEN_RPAREN       { $$ = type_create(TYPE_FUNCTION, $1, $3); };

optfuncinit : TOKEN_ASSIGN TOKEN_LBRACE block TOKEN_RBRACE  { $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $3, NULL, NULL); }
            | TOKEN_SEMI  { $$ = NULL; }
            ;

paramlist : TOKEN_IDENT TOKEN_COLON paramtype optparam  { $$ = param_list_create($1, $3, $4); }
          |  { $$ = NULL; }
          ;

paramtype : simpletype  { $$ = $1; }
          | arrparam    { $$ = $1; }
          ;

arrparam  : TOKEN_ARRAY TOKEN_LBRACKET TOKEN_RBRACKET paramtype    { $$ = type_create(TYPE_FUNCTION_ARRAY_PARAM, $4, NULL); };

optparam  : TOKEN_COMMA TOKEN_IDENT TOKEN_COLON paramtype optparam  { $$ = param_list_create($2, $4, $5); }
          |  { $$ = NULL; }
          ;

stmt : expr TOKEN_SEMI  { $$ = stmt_create(STMT_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
     | TOKEN_FOR TOKEN_LPAREN optexpr TOKEN_SEMI optexpr TOKEN_SEMI optexpr TOKEN_RPAREN stmt  { $$ = stmt_create(STMT_FOR, NULL, $3, $5, $7, $9, NULL, NULL); }
     | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt  { $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $3, NULL, $5, NULL, NULL); }
     | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN innerstmt TOKEN_ELSE innerstmt  { $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $3, NULL, $5, $7, NULL); }
     | TOKEN_PRINT expr arrlst TOKEN_SEMI  { struct expr* lst = expr_create(EXPR_ARG, $2, $3); $$ = stmt_create(STMT_PRINT, NULL, NULL, lst, NULL, NULL, NULL, NULL); }
     | TOKEN_PRINT TOKEN_SEMI  { $$ = stmt_create(STMT_PRINT, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
     | TOKEN_RETURN optexpr TOKEN_SEMI  { $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
     | decl  { $$ = stmt_create(STMT_DECL, $1, NULL, NULL, NULL, NULL, NULL, NULL); }
     | TOKEN_LBRACE block TOKEN_RBRACE  { $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $2, NULL, NULL); }
     ;

innerstmt : expr TOKEN_SEMI  { $$ = stmt_create(STMT_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
          | TOKEN_FOR TOKEN_LPAREN optexpr TOKEN_SEMI optexpr TOKEN_SEMI optexpr TOKEN_RPAREN innerstmt  { $$ = stmt_create(STMT_FOR, NULL, $3, $5, $7, $9, NULL, NULL); } 
          | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN innerstmt TOKEN_ELSE innerstmt  { $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $3, NULL, $5, $7, NULL); } 
          | TOKEN_PRINT expr arrlst TOKEN_SEMI  { struct expr* lst = expr_create(EXPR_ARG, $2, $3); $$ = stmt_create(STMT_PRINT, NULL, NULL, lst, NULL, NULL, NULL, NULL); }
          | TOKEN_PRINT TOKEN_SEMI  { $$ = stmt_create(STMT_PRINT, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
          | TOKEN_RETURN optexpr TOKEN_SEMI  { $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
          | decl  { $$ = stmt_create(STMT_DECL, $1, NULL, NULL, NULL, NULL, NULL, NULL); }
          | TOKEN_LBRACE block TOKEN_RBRACE  { $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $2, NULL, NULL); }
          ;

arrlst  : TOKEN_COMMA expr arrlst   { $$ = expr_create(EXPR_ARG, $2, $3); }
        |  { $$ = NULL; }
        ;

exprlst : TOKEN_COMMA expr exprlst  { $$ = expr_create(EXPR_LIST, $2, $3); }
        |  { $$ = NULL; }
        ;

optexpr : expr  { $$ = $1; }
        |  { $$ = NULL; }
        ;

expr : expr TOKEN_ASSIGN rightval  { $$ = expr_create(EXPR_ASSIGN, $1, $3); }
     | rightval                    { $$ = $1; }
     ;

rightval : rightval TOKEN_OR or_operand   { $$ = expr_create(EXPR_OR, $1, $3); }
         | or_operand                     { $$ = $1; }
         ;

or_operand : or_operand TOKEN_AND and_operand   { $$ = expr_create(EXPR_AND, $1, $3); }
           | and_operand                        { $$ = $1; }
           ;

and_operand: and_operand TOKEN_LT compared  { $$ = expr_create(EXPR_LT, $1, $3); }
           | and_operand TOKEN_LE compared  { $$ = expr_create(EXPR_LE, $1, $3); }
           | and_operand TOKEN_GT compared  { $$ = expr_create(EXPR_GT, $1, $3); }
           | and_operand TOKEN_GE compared  { $$ = expr_create(EXPR_GE, $1, $3); }
           | and_operand TOKEN_EQ compared  { $$ = expr_create(EXPR_EQ, $1, $3); }
           | and_operand TOKEN_NE compared  { $$ = expr_create(EXPR_NE, $1, $3); }
           | compared                       { $$ = $1; }
           ;

compared : compared TOKEN_PLUS term    { $$ = expr_create(EXPR_ADD, $1, $3); }
         | compared TOKEN_MINUS term   { $$ = expr_create(EXPR_SUB, $1, $3); }
         | term                    { $$ = $1; }
         ;

term : term TOKEN_MUL exponent  { $$ = expr_create(EXPR_MUL, $1, $3); }
     | term TOKEN_DIV exponent  { $$ = expr_create(EXPR_DIV, $1, $3); }
     | term TOKEN_MOD exponent  { $$ = expr_create(EXPR_MOD, $1, $3); }
     | exponent  { $$ = $1; }
     ;

exponent  : exponent TOKEN_EXP multiplier  { $$ = expr_create(EXPR_EXP, $1, $3); }
          | multiplier                     { $$ = $1; }
          ;

multiplier: TOKEN_MINUS factor     { $$ = expr_create(EXPR_NEG, NULL, $2); }
          | TOKEN_PLUS factor      { $$ = expr_create(EXPR_POS, NULL, $2); }
          | TOKEN_NOT factor       { $$ = expr_create(EXPR_NOT, NULL, $2); }
          | factor                 { $$ = $1; }
          ;

factor: value TOKEN_INCRE      { $$ = expr_create(EXPR_SELF_ADD, $1, NULL); }
      | value TOKEN_DECRE      { $$ = expr_create(EXPR_SELF_SUB, $1, NULL); }
      | value                  { $$ = $1; }
      ;

value: TOKEN_LPAREN expr TOKEN_RPAREN { $$ = $2; }
     | TOKEN_IDENT TOKEN_LPAREN expr arrlst TOKEN_RPAREN  { struct expr* name = expr_create_name($1); struct expr* args = expr_create(EXPR_ARG, $3, $4); $$ = expr_create(EXPR_CALL, name, args); }
     | TOKEN_IDENT TOKEN_LPAREN TOKEN_RPAREN  { struct expr* name = expr_create_name($1); $$ = expr_create(EXPR_CALL, name, NULL); }
     | TOKEN_INT_LITERAL              { $$ = expr_create_integer_literal($1); }
     | TOKEN_FLOAT_LITERAL            { $$ = expr_create_float_literal($1); }
     | TOKEN_CHAR_LITERAL             { $$ = expr_create_char_literal($1); }
     | TOKEN_STRING_LITERAL           { $$ = expr_create_string_literal($1); }
     | TOKEN_TRUE                     { $$ = expr_create_boolean_literal(1); }
     | TOKEN_FALSE                    { $$ = expr_create_boolean_literal(0); }
     | TOKEN_IDENT TOKEN_LBRACKET expr TOKEN_RBRACKET optarrvalue  { struct expr* name = expr_create_name($1); $3->right = $5; $$ = expr_create(EXPR_SUBSCRIPT, name, $3); }
     | TOKEN_IDENT  { $$ = expr_create_name($1); }
     ;

optarrvalue : optarrvalue TOKEN_LBRACKET expr TOKEN_RBRACKET  { $3->right = $1; $$ = $3; }
            |  { $$ = NULL; }
            ;

%%

int yyerror(char *s) {
  printf("parse error: %s\n", s);
  return 1;
}
int yyparsemain(FILE* file) {
  yyin = file;
  yyparse();
  return 0;
}
int yyprintmain(FILE* file) {
  yyin = file;
  yyparse();
  if (!root) {
    yyerror("empty root node");
  }
  decl_print(root, 0);
  return 0;
}
