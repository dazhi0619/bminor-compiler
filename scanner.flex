%{
#include "include/encoder.h"
#include "include/scanner.h"
#include "include/token.h"

#include <stdio.h>
#include <stdlib.h>
%}

/* Types */
INTEGER_LITERAL [+-]?[0-9]+
FLOAT_LITERAL [+-]?([0-9]*\.[0-9]+|[0-9]+(\.[0-9]+)?e[+-]?[0-9]+)
CHAR_LITERAL  \'([^\\\']|\\[abefnrtv\'\"]|\\0x[0-9A-F][0-9A-F])\'
STRING_LITERAL  \"([^\\\"]|\\.)*\"

/* Symbols */
DELIM [\n|\r\n|\ |\t]
COMMA ,
SEMICOLON ;
COLON :
PARENTHESIS \(|\)
BRACKET \[|\]
BRACE   \{|\}
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

{INTEGER_LITERAL}   { return TOKEN_INT; }
{FLOAT_LITERAL}     { return TOKEN_FLOAT; }
{CHAR_LITERAL}      { return TOKEN_CHAR; }
{STRING_LITERAL}    { return TOKEN_STRING; }
{COMMA}   { printf("COMMA\n"); }
{SEMICOLON}   { return TOKEN_SEMI; }
{COLON}   { printf("COLON\n"); }
\(        { return TOKEN_LPAREN; }
\)        { return TOKEN_RPAREN; }
{BRACKET}   { printf("BRACKET\n"); }
{BRACE}   { printf("BRACE\n"); }
{INCREMENT}   { printf("INCREMENT\n"); }
{DECREMENT}   { printf("DECREMENT\n"); }
{MINUS}   { return TOKEN_MINUS; }
{NOT}   { printf("NOT\n"); }
{EXPONENTIATION}   { printf("EXPONENTIATION\n"); }
{MULTIPLICATION}   { return TOKEN_MUL; }
{DIVISION}   { return TOKEN_DIV; }
{REMAINDER}   { printf("REMAINDER\n"); }
{ADDITION}   { return TOKEN_PLUS; }
{LT}   { printf("LT\n"); }
{LE}   { printf("LE\n"); }
{GT}   { printf("GT\n"); }
{GE}   { printf("GE\n"); }
{EQ}   { printf("EQ\n"); }
{NEQ}   { printf("NEQ\n"); }
{AND}   { printf("AND\n"); }
{OR}   { printf("OR\n"); }
{ASSIGNMENT}   { printf("ASSIGNMENT\n"); }
{ARRAY_KEYWORD}   { printf("ARRAY_KEYWORD\n"); }
{AUTO_KEYWORD}   { printf("AUTO_KEYWORD\n"); }
{BOOL_KEYWORD}   { printf("BOOL_KEYWORD\n"); }
{CHAR_KEYWORD}   { printf("CHAR_KEYWORD\n"); }
{ELSE_KEYWORD}   { printf("ELSE_KEYWORD\n"); }
{FALSE_KEYWORD}   { printf("FALSE_KEYWORD\n"); }
{FLOAT_KEYWORD}   { printf("FLOAT_KEYWORD\n"); }
{FOR_KEYWORD}   { printf("FOR_KEYWORD\n"); }
{FUNCTION_KEYWORD}   { printf("FUNCTION_KEYWORD\n"); }
{IF_KEYWORD}   { printf("IF_KEYWORD\n"); }
{INTEGER_KEYWORD}   { printf("INTEGER_KEYWORD\n"); }
{PRINT_KEYWORD}   { printf("PRINT_KEYWORD\n"); }
{RETURN_KEYWORD}   { printf("RETURN_KEYWORD\n"); }
{STRING_KEYWORD}   { printf("STRING_KEYWORD\n"); }
{TRUE_KEYWORD}   { printf("TRUE_KEYWORD\n"); }
{VOID_KEYWORD}   { printf("VOID_KEYWORD\n"); }
{WHILE_KEYWORD}   { printf("WHILE_KEYWORD\n"); }
{IDENT}             { printf("IDENTIFIER %s\n", yytext); }

.   { printf("ERROR: %s is unindentified.\n", yytext); return SCAN_ERROR; }

%%

int yywrap() { return 1; }
int yyscanmain(FILE* file) {
  yyin = file;
  if (yylex() == SCAN_ERROR) {
    return 1;
  }
}
