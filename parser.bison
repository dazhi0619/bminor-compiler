%{
#include "include/token.h"
#include "include/parser.h"

#include <stdio.h>
#include <stdlib.h>

extern int parser_result;
extern char* yytext;
extern int yylex();
extern FILE* yyin;

int yyerror(char* s);

int parser_result = 0;
%}

%token TOKEN_INT
%token TOKEN_FLOAT
%token TOKEN_CHAR
%token TOKEN_STRING

%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV

%token TOKEN_LPAREN
%token TOKEN_RPAREN

%token TOKEN_SEMI

%%

program : expr TOKEN_SEMI      { parser_result = $1; }
        ;

expr : expr TOKEN_PLUS term    { $$ = $1 + $3; }
     | expr TOKEN_MINUS term   { $$ = $1 - $3; }
     | term                    { $$ = $1; }
     ;

term : term TOKEN_MUL factor   { $$ = $1 * $3; }
     | term TOKEN_DIV factor   { $$ = $1 / $3; }
     | factor                  { $$ = $1; }
     ;

factor: TOKEN_MINUS factor     { $$ = -$2; }
      | TOKEN_LPAREN expr TOKEN_RPAREN { $$ = $2; }
      | TOKEN_INT              { $$ = atoi(yytext); }
      | TOKEN_FLOAT            { $$ = atof(yytext); }
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
