%{
#include "include/token.h"
#include "include/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int parser_result;
extern char* yytext;
extern int yylex();
extern FILE* yyin;

int yyerror(char* s);

int parser_result = 0;
%}

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
%token TOKEN_INT_LITERAL
%token TOKEN_FLOAT_LITERAL
%token TOKEN_STRING_LITERAL
%token TOKEN_CHAR_LITERAL

/* identifier */
%token TOKEN_IDENT

%%

program : program decl;
        |
        ;

decl : TOKEN_IDENT TOKEN_COLON type optinit
     | TOKEN_IDENT TOKEN_COLON TOKEN_FUNCTION functype optfuncinit
     ;

optinit : TOKEN_ASSIGN expr TOKEN_SEMI
        | TOKEN_ASSIGN arrliteral TOKEN_SEMI
        | TOKEN_SEMI
        ;

arrliteral : TOKEN_LBRACE expr exprlst TOKEN_RBRACE
           | TOKEN_LBRACE arrliteral arrliterallst TOKEN_RBRACE
           ;

arrliterallst : arrliterallst TOKEN_COMMA arrliteral
              |
              ;

block: block stmt
     | 
     ;

type : simpletype
     | arrtype
     ;

simpletype : TOKEN_INT
     | TOKEN_FLOAT
     | TOKEN_STRING
     | TOKEN_CHAR
     | TOKEN_BOOL
     | TOKEN_AUTO
     | TOKEN_VOID
     ;

arrtype   : TOKEN_ARRAY TOKEN_LBRACKET TOKEN_INT_LITERAL TOKEN_RBRACKET type;

functype  : type TOKEN_LPAREN paramlist TOKEN_RPAREN;

optfuncinit : TOKEN_ASSIGN TOKEN_LBRACE block TOKEN_RBRACE
            | TOKEN_SEMI
            ;

paramlist : TOKEN_IDENT TOKEN_COLON paramtype optparam
          | 
          ;

paramtype : simpletype
          | arrparam
          ;

arrparam  : TOKEN_ARRAY TOKEN_LBRACKET TOKEN_RBRACKET paramtype;

optparam  : optparam TOKEN_COMMA TOKEN_IDENT TOKEN_COLON paramtype
          |
          ;

stmt : expr TOKEN_SEMI
     | TOKEN_FOR TOKEN_LPAREN optexpr TOKEN_SEMI optexpr TOKEN_SEMI optexpr TOKEN_RPAREN stmt
     | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt
     | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN innerstmt TOKEN_ELSE innerstmt
     | TOKEN_PRINT expr exprlst TOKEN_SEMI
     | TOKEN_PRINT TOKEN_SEMI
     | TOKEN_RETURN optexpr TOKEN_SEMI
     | decl
     | TOKEN_LBRACE TOKEN_RBRACE
     | TOKEN_LBRACE stmt optstmt TOKEN_RBRACE
     ;

innerstmt : expr TOKEN_SEMI
          | TOKEN_FOR TOKEN_LPAREN optexpr TOKEN_SEMI optexpr TOKEN_SEMI optexpr TOKEN_RPAREN innerstmt
          | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN innerstmt TOKEN_ELSE innerstmt
          | TOKEN_PRINT expr exprlst TOKEN_SEMI
          | TOKEN_PRINT TOKEN_SEMI
          | TOKEN_RETURN optexpr TOKEN_SEMI
          | decl
          | TOKEN_LBRACE TOKEN_RBRACE
          | TOKEN_LBRACE stmt optstmt TOKEN_RBRACE
          ;

optstmt : stmt
        |
        ;

exprlst : exprlst TOKEN_COMMA expr
        | 
        ;

optexpr : expr
        |
        ;

expr : expr TOKEN_ASSIGN rightval  { $$ = $1 = $3; }
     | rightval                    { $$ = $1; }
     ;

rightval : rightval TOKEN_OR or_operand   { $$ = $1 || $3; }
         | or_operand                     { $$ = $1; }
         ;

or_operand : or_operand TOKEN_AND and_operand   { $$ = $1 && $3; }
           | and_operand                        { $$ = $1; }
           ;

and_operand: and_operand TOKEN_LT compared  { $$ = $1 < $3; }
           | and_operand TOKEN_LE compared  { $$ = $1 <= $3; }
           | and_operand TOKEN_GT compared  { $$ = $1 > $3; }
           | and_operand TOKEN_GE compared  { $$ = $1 >= $3; }
           | and_operand TOKEN_EQ compared  { $$ = $1 == $3; }
           | and_operand TOKEN_NE compared  { $$ = $1 != $3; }
           | compared                       { $$ = $1; }
           ;

compared : compared TOKEN_PLUS term    { $$ = $1 + $3; }
         | compared TOKEN_MINUS term   { $$ = $1 - $3; }
         | term                    { $$ = $1; }
         ;

term : term TOKEN_MUL exponent
     | term TOKEN_DIV exponent
     | term TOKEN_MOD exponent
     | exponent
     ;

exponent  : exponent TOKEN_EXP multiplier
          | multiplier                      { $$ = $1; }
          ;

multiplier: TOKEN_MINUS factor     { $$ = -$2; }
          | TOKEN_PLUS factor      { $$ = $2; }
          | TOKEN_NOT factor       { $$ = !$2; }
          | factor                 { $$ = $1; }
          ;

factor: value TOKEN_INCRE      { $$ = $1++; }
      | value TOKEN_DECRE      { $$ = $1--; }
      | value                  { $$ = $1; }
      ;

value: TOKEN_LPAREN expr TOKEN_RPAREN { $$ = $2; }
     | TOKEN_IDENT TOKEN_LPAREN expr exprlst TOKEN_RPAREN
     | TOKEN_IDENT TOKEN_LPAREN TOKEN_RPAREN
     | TOKEN_INT_LITERAL              { $$ = atoi(yytext); }
     | TOKEN_FLOAT_LITERAL            { $$ = atof(yytext); }
     | TOKEN_CHAR_LITERAL
     | TOKEN_STRING_LITERAL
     | TOKEN_TRUE                     { $$ = 1; }
     | TOKEN_FALSE                    { $$ = 0; }
     | TOKEN_IDENT TOKEN_LBRACKET expr TOKEN_RBRACKET optarrvalue
     | TOKEN_IDENT
     ;

optarrvalue : optarrvalue TOKEN_LBRACKET expr TOKEN_RBRACKET
            |
            ;

%%

int yyerror(char *s) {
  printf("parse error: %s\n", s);
  return 1;
}
int yyparsemain(FILE* file) {
  yyin = file;
  return yyparse();
}
