%{
#include "include/encoder.h"
#include "include/scanner.h"
#include "include/token.h"

#include <stdio.h>
#include <stdlib.h>
%}

/* Types */
INTEGER_LITERAL [0-9]+
FLOAT_LITERAL ([0-9]*\.[0-9]+|[0-9]+(\.[0-9]+)?e[+-]?[0-9]+)
CHAR_LITERAL  \'([^\\\']|\\[abefnrtv\'\"\\]|\\0x[0-9A-F][0-9A-F])\'
STRING_LITERAL  \"([^\\\"]|\\.)*\"

/* Symbols */
DELIM [\n|\r\n|\ |\t]
COMMA ,
SEMICOLON ;
COLON :
LPAREN \(
RPAREN \)
LBRACKET \[
RBRACKET \]
LBRACE \{
RBRACE \}
INCREMENT \+\+
DECREMENT --
MINUS  -
NOT !
EXPONENTIATION  \^
MULTIPLICATION  \*
DIVISION  \/
REMAINDER \%
ADDITION  \+
LT  <
LE  <=
GT  >
GE  >=
EQ  ==
NEQ !=
AND &&
OR  \|\|
ASSIGNMENT  =

/* Keywords */
ARRAY_KEYWORD array
AUTO_KEYWORD  auto
BOOL_KEYWORD  boolean
CHAR_KEYWORD  char
ELSE_KEYWORD  else
FALSE_KEYWORD false
FLOAT_KEYWORD float
FOR_KEYWORD for
FUNCTION_KEYWORD  function
IF_KEYWORD  if
INTEGER_KEYWORD integer
PRINT_KEYWORD print
RETURN_KEYWORD  return
STRING_KEYWORD  string
TRUE_KEYWORD  true
VOID_KEYWORD  void
WHILE_KEYWORD while

IDENT [a-zA-Z_][a-zA-Z_0-9]*
COMMENT (\/\*([^*]|(\*+([^*\/])))*\*+\/)|(\/\/[^\n]*)

%%

{COMMENT}           {}
{DELIM}             {}

{ADDITION}   { return TOKEN_PLUS; }
{DIVISION}   { return TOKEN_DIV; }
{INTEGER_LITERAL}   { yylval.integer = atoi(yytext); return TOKEN_INT_LITERAL; }
{FLOAT_LITERAL}     { yylval.floating = atof(yytext); return TOKEN_FLOAT_LITERAL; }
{CHAR_LITERAL}      { yylval.character = yytext[1]; return TOKEN_CHAR_LITERAL; }
{STRING_LITERAL}    { yylval.string = strdup(yytext + 1); yylval.string[strlen(yylval.string) - 1] = 0; return TOKEN_STRING_LITERAL; }
{COMMA}   { return TOKEN_COMMA; }
{SEMICOLON}   { return TOKEN_SEMI; }
{COLON}   { return TOKEN_COLON; }
{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}        { return TOKEN_RPAREN; }
{LBRACKET} { return TOKEN_LBRACKET; }
{RBRACKET} { return TOKEN_RBRACKET; }
{LBRACE}   { return TOKEN_LBRACE; }
{RBRACE}   { return TOKEN_RBRACE; }
{INCREMENT}   { return TOKEN_INCRE; }
{DECREMENT}   { return TOKEN_DECRE; }
{MINUS}   { return TOKEN_MINUS; }
{NOT}   { return TOKEN_NOT; }
{EXPONENTIATION}   { return TOKEN_EXP; }
{MULTIPLICATION}   { return TOKEN_MUL; }
{REMAINDER}   { return TOKEN_MOD; }
{LT}   { return TOKEN_LT; }
{LE}   { return TOKEN_LE; }
{GT}   { return TOKEN_GT; }
{GE}   { return TOKEN_GE; }
{EQ}   { return TOKEN_EQ; }
{NEQ}   { return TOKEN_NE; }
{AND}   { return TOKEN_AND; }
{OR}   { return TOKEN_OR; }
{ASSIGNMENT}   { return TOKEN_ASSIGN; }
{ARRAY_KEYWORD}   { return TOKEN_ARRAY; }
{AUTO_KEYWORD}   { return TOKEN_AUTO; }
{BOOL_KEYWORD}   { return TOKEN_BOOL; }
{CHAR_KEYWORD}   { return TOKEN_CHAR; }
{ELSE_KEYWORD}   { return TOKEN_ELSE; }
{FALSE_KEYWORD}   { return TOKEN_FALSE; }
{FLOAT_KEYWORD}   { return TOKEN_FLOAT; }
{FOR_KEYWORD}   { return TOKEN_FOR; }
{FUNCTION_KEYWORD}   { return TOKEN_FUNCTION; }
{IF_KEYWORD}   { return TOKEN_IF; }
{INTEGER_KEYWORD}   { return TOKEN_INT; }
{PRINT_KEYWORD}   { return TOKEN_PRINT; }
{RETURN_KEYWORD}   { return TOKEN_RETURN; }
{STRING_KEYWORD}   { return TOKEN_STRING; }
{TRUE_KEYWORD}   { return TOKEN_TRUE; }
{VOID_KEYWORD}   { return TOKEN_VOID; }
{WHILE_KEYWORD}   { return TOKEN_WHILE; }
{IDENT}             { yylval.string = strdup(yytext); return TOKEN_IDENT; }

.   { printf("ERROR: %s is unindentified.\n", yytext); return SCAN_ERROR; }

%%

int yywrap() { return 1; }
int yyscanmain(FILE* file) {
  yyin = file;
  if (yylex() == SCAN_ERROR) {
    return 1;
  }
  return 0;
}
