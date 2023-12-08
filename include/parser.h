#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

#include "ast.h"
int yyparsemain(FILE* file);
int yyprintmain(FILE* file);
int yyresolvemain(FILE* file);
int yytypecheckmain(FILE* file);
int yycodegenmain(FILE* filein, FILE* fileout);
#endif  // !PARSER_H
