/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_INCLUDE_TOKEN_H_INCLUDED
#define YY_YY_INCLUDE_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype {
  TOKEN_INT = 258,
  TOKEN_FLOAT = 259,
  TOKEN_CHAR = 260,
  TOKEN_STRING = 261,
  TOKEN_ARRAY = 262,
  TOKEN_AUTO = 263,
  TOKEN_BOOL = 264,
  TOKEN_TRUE = 265,
  TOKEN_FALSE = 266,
  TOKEN_VOID = 267,
  TOKEN_IF = 268,
  TOKEN_ELSE = 269,
  TOKEN_FOR = 270,
  TOKEN_FUNCTION = 271,
  TOKEN_PRINT = 272,
  TOKEN_RETURN = 273,
  TOKEN_WHILE = 274,
  TOKEN_LPAREN = 275,
  TOKEN_RPAREN = 276,
  TOKEN_LBRACKET = 277,
  TOKEN_RBRACKET = 278,
  TOKEN_INCRE = 279,
  TOKEN_DECRE = 280,
  TOKEN_NOT = 281,
  TOKEN_EXP = 282,
  TOKEN_MINUS = 283,
  TOKEN_DIV = 284,
  TOKEN_MOD = 285,
  TOKEN_PLUS = 286,
  TOKEN_MUL = 287,
  TOKEN_LT = 288,
  TOKEN_LE = 289,
  TOKEN_GT = 290,
  TOKEN_GE = 291,
  TOKEN_EQ = 292,
  TOKEN_NE = 293,
  TOKEN_AND = 294,
  TOKEN_OR = 295,
  TOKEN_ASSIGN = 296,
  TOKEN_LBRACE = 297,
  TOKEN_RBRACE = 298,
  TOKEN_SEMI = 299,
  TOKEN_COMMA = 300,
  TOKEN_COLON = 301,
  TOKEN_INT_LITERAL = 302,
  TOKEN_FLOAT_LITERAL = 303,
  TOKEN_STRING_LITERAL = 304,
  TOKEN_CHAR_LITERAL = 305,
  TOKEN_IDENT = 306
};
#endif

/* Value type.  */
#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED

union YYSTYPE {
#line 22 "parser.bison" /* yacc.c:1909  */

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

#line 119 "include/token.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
#define YYSTYPE_IS_TRIVIAL 1
#define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

int yyparse(void);

#endif /* !YY_YY_INCLUDE_TOKEN_H_INCLUDED  */
