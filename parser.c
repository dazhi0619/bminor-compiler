/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

#include "include/parser.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/ast.h"
#include "include/token.h"

extern int parser_result;
extern char *yytext;
extern int yylex();
extern FILE *yyin;

int yyerror(char *s);

int parser_result = 0;

struct decl *root = 0;

#line 87 "parser.c" /* yacc.c:339  */

#ifndef YY_NULLPTR
#if defined __cplusplus && 201103L <= __cplusplus
#define YY_NULLPTR nullptr
#else
#define YY_NULLPTR 0
#endif
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
#undef YYERROR_VERBOSE
#define YYERROR_VERBOSE 1
#else
#define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "token.h".  */
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
#line 22 "parser.bison" /* yacc.c:355  */

  struct decl *decl;
  struct stmt *stmt;
  struct expr *expr;
  struct type *type;
  struct param_list *param_list;
  struct symbol *symbol;
  char *string;
  char character;
  int integer;
  double floating;

#line 192 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
#define YYSTYPE_IS_TRIVIAL 1
#define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

int yyparse(void);

#endif /* !YY_YY_INCLUDE_TOKEN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "parser.c" /* yacc.c:358  */

#ifdef short
#undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
#ifdef __SIZE_TYPE__
#define YYSIZE_T __SIZE_TYPE__
#elif defined size_t
#define YYSIZE_T size_t
#elif !defined YYSIZE_T
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#define YYSIZE_T size_t
#else
#define YYSIZE_T unsigned int
#endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T)-1)

#ifndef YY_
#if defined YYENABLE_NLS && YYENABLE_NLS
#if ENABLE_NLS
#include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#define YY_(Msgid) dgettext("bison-runtime", Msgid)
#endif
#endif
#ifndef YY_
#define YY_(Msgid) Msgid
#endif
#endif

#ifndef YY_ATTRIBUTE
#if (defined __GNUC__ &&                                           \
     (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__))) || \
    defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#define YY_ATTRIBUTE(Spec) __attribute__(Spec)
#else
#define YY_ATTRIBUTE(Spec) /* empty */
#endif
#endif

#ifndef YY_ATTRIBUTE_PURE
#define YY_ATTRIBUTE_PURE YY_ATTRIBUTE((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
#define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE((__unused__))
#endif

#if !defined _Noreturn && \
    (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
#if defined _MSC_VER && 1200 <= _MSC_VER
#define _Noreturn __declspec(noreturn)
#else
#define _Noreturn YY_ATTRIBUTE((__noreturn__))
#endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
#define YYUSE(E) ((void)(E))
#else
#define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                 \
  _Pragma("GCC diagnostic push")                            \
      _Pragma("GCC diagnostic ignored \"-Wuninitialized\"") \
          _Pragma("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
#define YY_IGNORE_MAYBE_UNINITIALIZED_END _Pragma("GCC diagnostic pop")
#else
#define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
#define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
#define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if !defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#ifdef YYSTACK_USE_ALLOCA
#if YYSTACK_USE_ALLOCA
#ifdef __GNUC__
#define YYSTACK_ALLOC __builtin_alloca
#elif defined __BUILTIN_VA_ARG_INCR
#include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#elif defined _AIX
#define YYSTACK_ALLOC __alloca
#elif defined _MSC_VER
#include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#define alloca _alloca
#else
#define YYSTACK_ALLOC alloca
#if !defined _ALLOCA_H && !defined EXIT_SUCCESS
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
/* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#endif
#endif
#endif
#endif

#ifdef YYSTACK_ALLOC
/* Pacify GCC's 'empty if-body' warning.  */
#define YYSTACK_FREE(Ptr) \
  do { /* empty */        \
    ;                     \
  } while (0)
#ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
   and a page size can be as small as 4096 bytes.  So we cannot safely
   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
   to allow for a few compiler-allocated temporary stack slots.  */
#define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#endif
#else
#define YYSTACK_ALLOC YYMALLOC
#define YYSTACK_FREE YYFREE
#ifndef YYSTACK_ALLOC_MAXIMUM
#define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#endif
#if (defined __cplusplus && !defined EXIT_SUCCESS && \
     !((defined YYMALLOC || defined malloc) &&       \
       (defined YYFREE || defined free)))
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#endif
#ifndef YYMALLOC
#define YYMALLOC malloc
#if !defined malloc && !defined EXIT_SUCCESS
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#ifndef YYFREE
#define YYFREE free
#if !defined free && !defined EXIT_SUCCESS
void free(void *); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

#if (!defined yyoverflow &&   \
     (!defined __cplusplus || \
      (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc {
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
#define YYSTACK_GAP_MAXIMUM (sizeof(union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
#define YYSTACK_BYTES(N) \
  ((N) * (sizeof(yytype_int16) + sizeof(YYSTYPE)) + YYSTACK_GAP_MAXIMUM)

#define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
#define YYSTACK_RELOCATE(Stack_alloc, Stack)                         \
  do {                                                               \
    YYSIZE_T yynewbytes;                                             \
    YYCOPY(&yyptr->Stack_alloc, Stack, yysize);                      \
    Stack = &yyptr->Stack_alloc;                                     \
    yynewbytes = yystacksize * sizeof(*Stack) + YYSTACK_GAP_MAXIMUM; \
    yyptr += yynewbytes / sizeof(*yyptr);                            \
  } while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
#ifndef YYCOPY
#if defined __GNUC__ && 1 < __GNUC__
#define YYCOPY(Dst, Src, Count) \
  __builtin_memcpy(Dst, Src, (Count) * sizeof(*(Src)))
#else
#define YYCOPY(Dst, Src, Count)                                  \
  do {                                                           \
    YYSIZE_T yyi;                                                \
    for (yyi = 0; yyi < (Count); yyi++) (Dst)[yyi] = (Src)[yyi]; \
  } while (0)
#endif
#endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 32
/* YYNRULES -- Number of rules.  */
#define YYNRULES 99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES 235

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK 2
#define YYMAXUTOK 306

#define YYTRANSLATE(YYX) \
  ((unsigned int)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] = {
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
    2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
    49, 50, 51};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] = {
    0,   105, 105, 106, 109, 110, 113, 114, 115, 118, 119, 122, 123, 126, 127,
    130, 131, 134, 135, 136, 137, 138, 139, 140, 143, 145, 147, 148, 151, 152,
    155, 156, 159, 161, 162, 165, 166, 167, 168, 169, 170, 171, 172, 173, 176,
    177, 178, 179, 180, 181, 182, 183, 186, 187, 190, 191, 194, 195, 198, 199,
    202, 203, 206, 207, 210, 211, 212, 213, 214, 215, 216, 219, 220, 221, 224,
    225, 226, 227, 230, 231, 234, 235, 236, 237, 240, 241, 242, 245, 246, 247,
    248, 249, 250, 251, 252, 253, 254, 255, 258, 259};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {"$end",
                                      "error",
                                      "$undefined",
                                      "TOKEN_INT",
                                      "TOKEN_FLOAT",
                                      "TOKEN_CHAR",
                                      "TOKEN_STRING",
                                      "TOKEN_ARRAY",
                                      "TOKEN_AUTO",
                                      "TOKEN_BOOL",
                                      "TOKEN_TRUE",
                                      "TOKEN_FALSE",
                                      "TOKEN_VOID",
                                      "TOKEN_IF",
                                      "TOKEN_ELSE",
                                      "TOKEN_FOR",
                                      "TOKEN_FUNCTION",
                                      "TOKEN_PRINT",
                                      "TOKEN_RETURN",
                                      "TOKEN_WHILE",
                                      "TOKEN_LPAREN",
                                      "TOKEN_RPAREN",
                                      "TOKEN_LBRACKET",
                                      "TOKEN_RBRACKET",
                                      "TOKEN_INCRE",
                                      "TOKEN_DECRE",
                                      "TOKEN_NOT",
                                      "TOKEN_EXP",
                                      "TOKEN_MINUS",
                                      "TOKEN_DIV",
                                      "TOKEN_MOD",
                                      "TOKEN_PLUS",
                                      "TOKEN_MUL",
                                      "TOKEN_LT",
                                      "TOKEN_LE",
                                      "TOKEN_GT",
                                      "TOKEN_GE",
                                      "TOKEN_EQ",
                                      "TOKEN_NE",
                                      "TOKEN_AND",
                                      "TOKEN_OR",
                                      "TOKEN_ASSIGN",
                                      "TOKEN_LBRACE",
                                      "TOKEN_RBRACE",
                                      "TOKEN_SEMI",
                                      "TOKEN_COMMA",
                                      "TOKEN_COLON",
                                      "TOKEN_INT_LITERAL",
                                      "TOKEN_FLOAT_LITERAL",
                                      "TOKEN_STRING_LITERAL",
                                      "TOKEN_CHAR_LITERAL",
                                      "TOKEN_IDENT",
                                      "$accept",
                                      "program",
                                      "decl",
                                      "optinit",
                                      "arrliteral",
                                      "arrliterallst",
                                      "block",
                                      "type",
                                      "simpletype",
                                      "arrtype",
                                      "functype",
                                      "optfuncinit",
                                      "paramlist",
                                      "paramtype",
                                      "arrparam",
                                      "optparam",
                                      "stmt",
                                      "innerstmt",
                                      "arrlst",
                                      "exprlst",
                                      "optexpr",
                                      "expr",
                                      "rightval",
                                      "or_operand",
                                      "and_operand",
                                      "compared",
                                      "term",
                                      "exponent",
                                      "multiplier",
                                      "factor",
                                      "value",
                                      "optarrvalue",
                                      YY_NULLPTR};
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] = {
    0,   256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267,
    268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280,
    281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293,
    294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306};
#endif

#define YYPACT_NINF -148

#define yypact_value_is_default(Yystate) (!!((Yystate) == (-148)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) 0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] = {
    -19,  -5,   66,   -19,  160,  -148, -148, -148, -148, -148, -148, 40,
    -148, -148, -148, 384,  37,   -148, -148, 335,  50,   42,   232,  -148,
    -148, -148, -148, 335,  82,   82,   82,   -148, -148, -148, -148, 34,
    48,   43,   54,   49,   13,   -7,   35,   71,   -148, -148, 12,   45,
    73,   -148, -148, 232,  75,   62,   -13,  -148, -148, -148, 265,  335,
    384,  335,  335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
    335,  335,  335,  335,  -148, -148, 77,   96,   94,   83,   -26,  -148,
    -148, -148, -148, -11,  3,    -148, 54,   49,   13,   -7,   -7,   -7,
    -7,   -7,   -7,   35,   35,   71,   71,   71,   -148, 394,  -148, 107,
    119,  277,  335,  94,   -4,   -148, 97,   94,   69,   105,  112,  335,
    114,  335,  150,  -148, 148,  -148, 129,  -148, 335,  335,  -148, -11,
    137,  141,  -148, -148, -148, 83,   -148, -26,  -148, -11,  -148, 163,
    165,  144,  -148, -8,   153,  154,  -148, -148, -148, -148, -148, 335,
    394,  146,  176,  335,  -148, 4,    -148, 394,  183,  185,  291,  335,
    94,   192,  -148, 196,  80,   167,  -148, 129,  335,  335,  198,  -11,
    169,  172,  220,  202,  335,  -148, -1,   173,  178,  206,  218,  216,
    219,  323,  335,  94,   -148, -148, 93,   223,  176,  335,  227,  335,
    335,  -148, -11,  201,  204,  -148, 94,   235,  209,  2,    210,  211,
    -148, -148, -148, 220,  335,  220,  335,  -148, 236,  238,  242,  213,
    176,  220,  335,  -148, -148, 240,  220};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] = {
    3,  0,  0,  3,  0,  1,  2,  17, 18, 20, 19, 0,  22, 21, 23, 0,  0,  15, 16,
    57, 0,  0,  0,  8,  4,  94, 95, 0,  0,  0,  0,  90, 91, 93, 92, 97, 0,  56,
    59, 61, 63, 70, 73, 77, 79, 83, 86, 29, 0,  27, 5,  0,  0,  0,  0,  82, 80,
    81, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    84, 85, 0,  0,  14, 12, 55, 7,  6,  87, 89, 53, 0,  24, 58, 60, 62, 64, 65,
    66, 67, 68, 69, 72, 71, 75, 76, 74, 78, 0,  25, 0,  0,  0,  57, 14, 97, 42,
    0,  14, 0,  0,  0,  0,  0,  0,  0,  99, 0,  30, 34, 31, 0,  57, 40, 53, 0,
    0,  26, 13, 35, 12, 10, 55, 9,  53, 88, 96, 0,  0,  28, 0,  0,  0,  41, 43,
    11, 54, 52, 0,  0,  0,  0,  57, 39, 0,  32, 0,  0,  0,  0,  57, 14, 42, 37,
    0,  0,  0,  98, 34, 0,  57, 40, 53, 0,  0,  0,  35, 57, 33, 0,  0,  0,  41,
    43, 0,  0,  0,  57, 14, 50, 38, 0,  0,  0,  57, 39, 0,  57, 48, 53, 0,  0,
    44, 0,  0,  0,  0,  0,  0,  49, 51, 36, 0,  57, 0,  57, 47, 38, 0,  0,  0,
    0,  0,  57, 45, 46, 0,  0};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] = {
    -148, 261,  0,    -148, -42, 128,  -110, -3,   -95,  -148, -148,
    -148, -148, -134, -148, 91,  -141, -147, -127, 133,  -104, -20,
    212,  215,  221,  85,   6,   87,   203,  149,  -148, -148};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] = {
    -1,  2,   113, 24,  52, 118, 114, 16, 17, 18, 21, 50, 79, 126, 127, 146,
    115, 231, 122, 120, 36, 37,  38,  39, 40, 41, 42, 43, 44, 45,  46,  143};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] = {
    3,   133, 53,  3,   149, 135, 132, 54,  85,  81,  125, 171, 20,  158, 154,
    61,  58,  170, 59,  119, 200, 70,  162, 221, 71,  148, 123, 174, 61,  175,
    61,  82,  1,   61,  121, 197, 76,  77,  87,  88,  61,  4,   4,   61,  61,
    61,  64,  65,  66,  67,  68,  69,  188, 211, 58,  173, 59,  89,  181, 170,
    116, 125, 19,  180, 72,  73,  5,   74,  125, 218, 47,  60,  224, 187, 226,
    137, 99,  100, 22,  215, 199, 23,  232, 48,  61,  208, 49,  218, 63,  131,
    207, 116, 25,  26,  62,  116, 78,  212, 75,  139, 214, 141, 27,  61,  25,
    26,  84,  107, 147, 108, 61,  109, 110, 136, 27,  80,  225, 106, 227, 83,
    28,  61,  29,  105, 183, 30,  233, 128, 117, 31,  32,  33,  34,  35,  61,
    161, 111, 209, 172, 129, 134, 31,  32,  33,  34,  112, 179, 51,  116, 93,
    94,  95,  96,  97,  98,  138, 186, 140, 169, 101, 102, 103, 198, 7,   8,
    9,   10,  11,  12,  13,  144, 142, 14,  206, 145, 116, 15,  55,  56,  57,
    172, 150, 196, 213, 151, 155, 25,  26,  156, 164, 116, 165, 163, 166, 167,
    157, 27,  159, 160, 198, 169, 198, 28,  176, 29,  177, -50, 30,  172, 198,
    182, 184, -48, 189, 198, 190, -44, 201, 168, 196, -49, 196, 202, 31,  32,
    33,  34,  112, 169, 196, 25,  26,  -51, 191, 196, 192, 203, 193, 194, 204,
    27,  -47, 25,  26,  210, 216, 28,  217, 29,  219, -46, 30,  27,  220, 222,
    223, 229, 230, 28,  228, 29,  234, 195, 30,  6,   152, 185, 31,  32,  33,
    34,  112, 153, 90,  51,  25,  26,  91,  104, 31,  32,  33,  34,  35,  92,
    27,  86,  25,  26,  0,   0,   28,  0,   29,  0,   0,   30,  27,  0,   0,
    0,   25,  26,  28,  0,   29,  0,   0,   30,  0,   0,   27,  31,  32,  33,
    34,  35,  28,  0,   29,  0,   130, 30,  0,   31,  32,  33,  34,  35,  0,
    0,   0,   0,   25,  26,  178, 0,   0,   31,  32,  33,  34,  35,  27,  0,
    25,  26,  0,   0,   28,  0,   29,  0,   0,   30,  27,  0,   0,   0,   0,
    0,   28,  0,   29,  0,   0,   30,  205, 0,   0,   31,  32,  33,  34,  35,
    0,   0,   0,   0,   0,   0,   0,   31,  32,  33,  34,  35,  7,   8,   9,
    10,  11,  12,  13,  0,   0,   14,  7,   8,   9,   10,  124, 12,  13,  0,
    0,   14};

static const yytype_int16 yycheck[] = {
    0,   111, 22,  3,   131, 115, 110, 27,  21,  51,  105, 158, 15,  21,  141,
    41,  20,  158, 22,  45,  21,  28,  156, 21,  31,  129, 23,  23,  41,  163,
    41,  51,  51,  41,  45,  182, 24,  25,  58,  59,  41,  46,  46,  41,  41,
    41,  33,  34,  35,  36,  37,  38,  179, 200, 20,  159, 22,  60,  168, 200,
    80,  156, 22,  167, 29,  30,  0,   32,  163, 210, 20,  23,  219, 177, 221,
    117, 70,  71,  41,  206, 184, 44,  229, 41,  41,  195, 44,  228, 39,  109,
    194, 111, 10,  11,  40,  115, 51,  201, 27,  119, 204, 121, 20,  41,  10,
    11,  44,  13,  128, 15,  41,  17,  18,  44,  20,  42,  220, 21,  222, 44,
    26,  41,  28,  46,  44,  31,  230, 20,  45,  47,  48,  49,  50,  51,  41,
    155, 42,  44,  158, 20,  43,  47,  48,  49,  50,  51,  166, 42,  168, 64,
    65,  66,  67,  68,  69,  43,  176, 43,  158, 72,  73,  74,  182, 3,   4,
    5,   6,   7,   8,   9,   22,  21,  12,  193, 45,  195, 16,  28,  29,  30,
    200, 44,  182, 203, 43,  22,  10,  11,  23,  13,  210, 15,  46,  17,  18,
    51,  20,  44,  44,  219, 200, 221, 26,  20,  28,  20,  14,  31,  228, 229,
    14,  44,  14,  44,  234, 43,  14,  44,  42,  219, 14,  221, 44,  47,  48,
    49,  50,  51,  228, 229, 10,  11,  14,  13,  234, 15,  20,  17,  18,  20,
    20,  14,  10,  11,  21,  44,  26,  43,  28,  14,  14,  31,  20,  44,  44,
    44,  14,  44,  26,  21,  28,  21,  42,  31,  3,   137, 175, 47,  48,  49,
    50,  51,  139, 61,  42,  10,  11,  62,  75,  47,  48,  49,  50,  51,  63,
    20,  21,  10,  11,  -1,  -1,  26,  -1,  28,  -1,  -1,  31,  20,  -1,  -1,
    -1,  10,  11,  26,  -1,  28,  -1,  -1,  31,  -1,  -1,  20,  47,  48,  49,
    50,  51,  26,  -1,  28,  -1,  44,  31,  -1,  47,  48,  49,  50,  51,  -1,
    -1,  -1,  -1,  10,  11,  44,  -1,  -1,  47,  48,  49,  50,  51,  20,  -1,
    10,  11,  -1,  -1,  26,  -1,  28,  -1,  -1,  31,  20,  -1,  -1,  -1,  -1,
    -1,  26,  -1,  28,  -1,  -1,  31,  44,  -1,  -1,  47,  48,  49,  50,  51,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  47,  48,  49,  50,  51,  3,   4,   5,
    6,   7,   8,   9,   -1,  -1,  12,  3,   4,   5,   6,   7,   8,   9,   -1,
    -1,  12};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] = {
    0,  51, 53, 54, 46, 0,  53, 3,  4,  5,  6,  7,  8,  9,  12, 16, 59, 60, 61,
    22, 59, 62, 41, 44, 55, 10, 11, 20, 26, 28, 31, 47, 48, 49, 50, 51, 72, 73,
    74, 75, 76, 77, 78, 79, 80, 81, 82, 20, 41, 44, 63, 42, 56, 73, 73, 81, 81,
    81, 20, 22, 23, 41, 40, 39, 33, 34, 35, 36, 37, 38, 28, 31, 29, 30, 32, 27,
    24, 25, 51, 64, 42, 56, 73, 44, 44, 21, 21, 73, 73, 59, 74, 75, 76, 77, 77,
    77, 77, 77, 77, 78, 78, 79, 79, 79, 80, 46, 21, 13, 15, 17, 18, 42, 51, 54,
    58, 68, 73, 45, 57, 45, 71, 45, 70, 23, 7,  60, 65, 66, 20, 20, 44, 73, 72,
    58, 43, 58, 44, 56, 43, 73, 43, 73, 21, 83, 22, 45, 67, 73, 72, 70, 44, 43,
    57, 71, 70, 22, 23, 51, 21, 44, 44, 73, 65, 46, 13, 15, 17, 18, 42, 54, 68,
    69, 73, 72, 23, 65, 20, 20, 44, 73, 72, 58, 14, 44, 44, 67, 73, 72, 70, 44,
    43, 13, 15, 17, 18, 42, 54, 69, 73, 72, 21, 44, 44, 20, 20, 44, 73, 72, 58,
    44, 21, 69, 72, 73, 72, 70, 44, 43, 68, 14, 44, 21, 44, 44, 69, 72, 69, 72,
    21, 14, 44, 69, 69, 72, 21};

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] = {
    0,  52, 53, 53, 54, 54, 55, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59,
    60, 60, 60, 60, 60, 60, 60, 61, 62, 63, 63, 64, 64, 65, 65, 66, 67,
    67, 68, 68, 68, 68, 68, 68, 68, 68, 68, 69, 69, 69, 69, 69, 69, 69,
    69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76, 76, 76,
    76, 76, 76, 77, 77, 77, 78, 78, 78, 78, 79, 79, 80, 80, 80, 80, 81,
    81, 81, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83};

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] = {
    0, 2, 2, 0, 4, 5, 3, 3, 1, 4, 4, 3, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5,
    4, 4, 1, 4, 0, 1, 1, 4, 5, 0, 2, 9, 5, 7, 4, 2, 3, 1, 3, 2, 9, 7, 4, 2, 3,
    1, 3, 3, 0, 3, 0, 1, 0, 3, 1, 3, 1, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 3, 1, 3,
    3, 3, 1, 3, 1, 2, 2, 2, 1, 2, 2, 1, 3, 5, 3, 1, 1, 1, 1, 1, 1, 5, 1, 4, 0};

#define yyerrok (yyerrstatus = 0)
#define yyclearin (yychar = YYEMPTY)
#define YYEMPTY (-2)
#define YYEOF 0

#define YYACCEPT goto yyacceptlab
#define YYABORT goto yyabortlab
#define YYERROR goto yyerrorlab

#define YYRECOVERING() (!!yyerrstatus)

#define YYBACKUP(Token, Value)                      \
  do                                                \
    if (yychar == YYEMPTY) {                        \
      yychar = (Token);                             \
      yylval = (Value);                             \
      YYPOPSTACK(yylen);                            \
      yystate = *yyssp;                             \
      goto yybackup;                                \
    } else {                                        \
      yyerror(YY_("syntax error: cannot back up")); \
      YYERROR;                                      \
    }                                               \
  while (0)

/* Error token number */
#define YYTERROR 1
#define YYERRCODE 256

/* Enable debugging if requested.  */
#if YYDEBUG

#ifndef YYFPRINTF
#include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#define YYFPRINTF fprintf
#endif

#define YYDPRINTF(Args)          \
  do {                           \
    if (yydebug) YYFPRINTF Args; \
  } while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
#define YY_LOCATION_PRINT(File, Loc) ((void)0)
#endif

#define YY_SYMBOL_PRINT(Title, Type, Value, Location) \
  do {                                                \
    if (yydebug) {                                    \
      YYFPRINTF(stderr, "%s ", Title);                \
      yy_symbol_print(stderr, Type, Value);           \
      YYFPRINTF(stderr, "\n");                        \
    }                                                 \
  } while (0)

/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void yy_symbol_value_print(FILE *yyoutput, int yytype,
                                  YYSTYPE const *const yyvaluep) {
  FILE *yyo = yyoutput;
  YYUSE(yyo);
  if (!yyvaluep) return;
#ifdef YYPRINT
  if (yytype < YYNTOKENS) YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
#endif
  YYUSE(yytype);
}

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void yy_symbol_print(FILE *yyoutput, int yytype,
                            YYSTYPE const *const yyvaluep) {
  YYFPRINTF(yyoutput, "%s %s (", yytype < YYNTOKENS ? "token" : "nterm",
            yytname[yytype]);

  yy_symbol_value_print(yyoutput, yytype, yyvaluep);
  YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void yy_stack_print(yytype_int16 *yybottom, yytype_int16 *yytop) {
  YYFPRINTF(stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++) {
    int yybot = *yybottom;
    YYFPRINTF(stderr, " %d", yybot);
  }
  YYFPRINTF(stderr, "\n");
}

#define YY_STACK_PRINT(Bottom, Top)               \
  do {                                            \
    if (yydebug) yy_stack_print((Bottom), (Top)); \
  } while (0)

/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void yy_reduce_print(yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule) {
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n", yyrule - 1,
            yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++) {
    YYFPRINTF(stderr, "   $%d = ", yyi + 1);
    yy_symbol_print(stderr, yystos[yyssp[yyi + 1 - yynrhs]],
                    &(yyvsp[(yyi + 1) - (yynrhs)]));
    YYFPRINTF(stderr, "\n");
  }
}

#define YY_REDUCE_PRINT(Rule)                         \
  do {                                                \
    if (yydebug) yy_reduce_print(yyssp, yyvsp, Rule); \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
#define YYDPRINTF(Args)
#define YY_SYMBOL_PRINT(Title, Type, Value, Location)
#define YY_STACK_PRINT(Bottom, Top)
#define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if YYERROR_VERBOSE

#ifndef yystrlen
#if defined __GLIBC__ && defined _STRING_H
#define yystrlen strlen
#else
/* Return the length of YYSTR.  */
static YYSIZE_T yystrlen(const char *yystr) {
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++) continue;
  return yylen;
}
#endif
#endif

#ifndef yystpcpy
#if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#define yystpcpy stpcpy
#else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *yystpcpy(char *yydest, const char *yysrc) {
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0') continue;

  return yyd - 1;
}
#endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T yytnamerr(char *yyres, const char *yystr) {
  if (*yystr == '"') {
    YYSIZE_T yyn = 0;
    char const *yyp = yystr;

    for (;;) switch (*++yyp) {
        case '\'':
        case ',':
          goto do_not_strip_quotes;

        case '\\':
          if (*++yyp != '\\') goto do_not_strip_quotes;
          /* Fall through.  */
        default:
          if (yyres) yyres[yyn] = *yyp;
          yyn++;
          break;

        case '"':
          if (yyres) yyres[yyn] = '\0';
          return yyn;
      }
  do_not_strip_quotes:;
  }

  if (!yyres) return yystrlen(yystr);

  return yystpcpy(yyres, yystr) - yyres;
}
#endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int yysyntax_error(YYSIZE_T *yymsg_alloc, char **yymsg,
                          yytype_int16 *yyssp, int yytoken) {
  YYSIZE_T yysize0 = yytnamerr(YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY) {
    int yyn = yypact[*yyssp];
    yyarg[yycount++] = yytname[yytoken];
    if (!yypact_value_is_default(yyn)) {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR &&
            !yytable_value_is_error(yytable[yyx + yyn])) {
          if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM) {
            yycount = 1;
            yysize = yysize0;
            break;
          }
          yyarg[yycount++] = yytname[yyx];
          {
            YYSIZE_T yysize1 = yysize + yytnamerr(YY_NULLPTR, yytname[yyx]);
            if (!(yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
              return 2;
            yysize = yysize1;
          }
        }
    }
  }

  switch (yycount) {
#define YYCASE_(N, S) \
  case N:             \
    yyformat = S;     \
    break
    YYCASE_(0, YY_("syntax error"));
    YYCASE_(1, YY_("syntax error, unexpected %s"));
    YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
    YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
    YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
    YYCASE_(5,
            YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
  }

  {
    YYSIZE_T yysize1 = yysize + yystrlen(yyformat);
    if (!(yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)) return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize) {
    *yymsg_alloc = 2 * yysize;
    if (!(yysize <= *yymsg_alloc && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
      *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
    return 1;
  }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount) {
        yyp += yytnamerr(yyp, yyarg[yyi++]);
        yyformat += 2;
      } else {
        yyp++;
        yyformat++;
      }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep) {
  YYUSE(yyvaluep);
  if (!yymsg) yymsg = "Deleting";
  YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE(yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;

/*----------.
| yyparse.  |
`----------*/

int yyparse(void) {
  int yystate;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;

  /* The stacks and their tools:
     'yyss': related to states.
     'yyvs': related to semantic values.

     Refer to the stacks through separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs;
  YYSTYPE *yyvsp;

  YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N) (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

  /*------------------------------------------------------------.
  | yynewstate -- Push a new state, which is found in yystate.  |
  `------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp) {
    /* Get the current used size of the three stacks, in elements.  */
    YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
    {
      /* Give user a chance to reallocate the stack.  Use copies of
         these so that the &'s don't force the real ones into
         memory.  */
      YYSTYPE *yyvs1 = yyvs;
      yytype_int16 *yyss1 = yyss;

      /* Each stack pointer address is followed by the size of the
         data in use in that stack, in bytes.  This used to be a
         conditional around just the two extra args, but that might
         be undefined if yyoverflow is a macro.  */
      yyoverflow(YY_("memory exhausted"), &yyss1, yysize * sizeof(*yyssp),
                 &yyvs1, yysize * sizeof(*yyvsp), &yystacksize);

      yyss = yyss1;
      yyvs = yyvs1;
    }
#else /* no yyoverflow */
#ifndef YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    /* Extend the stack our own way.  */
    if (YYMAXDEPTH <= yystacksize) goto yyexhaustedlab;
    yystacksize *= 2;
    if (YYMAXDEPTH < yystacksize) yystacksize = YYMAXDEPTH;

    {
      yytype_int16* yyss1 = yyss;
      union yyalloc* yyptr =
          (union yyalloc*)YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
      if (!yyptr) goto yyexhaustedlab;
      YYSTACK_RELOCATE(yyss_alloc, yyss);
      YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#undef YYSTACK_RELOCATE
      if (yyss1 != yyssa) YYSTACK_FREE(yyss1);
    }
#endif
#endif /* no yyoverflow */

    yyssp = yyss + yysize - 1;
    yyvsp = yyvs + yysize - 1;

    YYDPRINTF((stderr, "Stack size increased to %lu\n",
               (unsigned long int)yystacksize));

    if (yyss + yystacksize - 1 <= yyssp) YYABORT;
  }

  YYDPRINTF((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL) YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default(yyn)) goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY) {
    YYDPRINTF((stderr, "Reading a token: "));
    yychar = yylex();
  }

  if (yychar <= YYEOF) {
    yychar = yytoken = YYEOF;
    YYDPRINTF((stderr, "Now at end of input.\n"));
  } else {
    yytoken = YYTRANSLATE(yychar);
    YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
  }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken) goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0) {
    if (yytable_value_is_error(yyn)) goto yyerrlab;
    yyn = -yyn;
    goto yyreduce;
  }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus) yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;

/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0) goto yyerrlab;
  goto yyreduce;

/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1 - yylen];

  YY_REDUCE_PRINT(yyn);
  switch (yyn) {
    case 2:
#line 105 "parser.bison" /* yacc.c:1646  */
    {
      (yyvsp[-1].decl)->next = (yyvsp[0].decl);
      root = (yyvsp[-1].decl);
    }
#line 1481 "parser.c" /* yacc.c:1646  */
    break;

    case 3:
#line 106 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.decl) = NULL;
      root = NULL;
    }
#line 1487 "parser.c" /* yacc.c:1646  */
    break;

    case 4:
#line 109 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.decl) = decl_create((yyvsp[-3].string), (yyvsp[-1].type),
                                 (yyvsp[0].expr), NULL, NULL);
    }
#line 1493 "parser.c" /* yacc.c:1646  */
    break;

    case 5:
#line 110 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.decl) = decl_create((yyvsp[-4].string), (yyvsp[-1].type), NULL,
                                 (yyvsp[0].stmt), NULL);
    }
#line 1499 "parser.c" /* yacc.c:1646  */
    break;

    case 6:
#line 113 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1505 "parser.c" /* yacc.c:1646  */
    break;

    case 7:
#line 114 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1511 "parser.c" /* yacc.c:1646  */
    break;

    case 8:
#line 115 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 1517 "parser.c" /* yacc.c:1646  */
    break;

    case 9:
#line 118 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *head =
          expr_create(EXPR_LIST, (yyvsp[-2].expr), (yyvsp[-1].expr));
      (yyval.expr) = expr_create(EXPR_LIST, NULL, head);
    }
#line 1523 "parser.c" /* yacc.c:1646  */
    break;

    case 10:
#line 119 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *head =
          expr_create(EXPR_LIST, (yyvsp[-2].expr), (yyvsp[-1].expr));
      (yyval.expr) = expr_create(EXPR_LIST, NULL, head);
    }
#line 1529 "parser.c" /* yacc.c:1646  */
    break;

    case 11:
#line 122 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 1535 "parser.c" /* yacc.c:1646  */
    break;

    case 12:
#line 123 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 1541 "parser.c" /* yacc.c:1646  */
    break;

    case 13:
#line 126 "parser.bison" /* yacc.c:1646  */
    {
      (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
      (yyval.stmt) = (yyvsp[-1].stmt);
    }
#line 1547 "parser.c" /* yacc.c:1646  */
    break;

    case 14:
#line 127 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = NULL;
    }
#line 1553 "parser.c" /* yacc.c:1646  */
    break;

    case 15:
#line 130 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = (yyvsp[0].type);
    }
#line 1559 "parser.c" /* yacc.c:1646  */
    break;

    case 16:
#line 131 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = (yyvsp[0].type);
    }
#line 1565 "parser.c" /* yacc.c:1646  */
    break;

    case 17:
#line 134 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL);
    }
#line 1571 "parser.c" /* yacc.c:1646  */
    break;

    case 18:
#line 135 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_FLOAT, NULL, NULL);
    }
#line 1577 "parser.c" /* yacc.c:1646  */
    break;

    case 19:
#line 136 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_STRING, NULL, NULL);
    }
#line 1583 "parser.c" /* yacc.c:1646  */
    break;

    case 20:
#line 137 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_CHARACTER, NULL, NULL);
    }
#line 1589 "parser.c" /* yacc.c:1646  */
    break;

    case 21:
#line 138 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL);
    }
#line 1595 "parser.c" /* yacc.c:1646  */
    break;

    case 22:
#line 139 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_VOID, NULL, NULL);
    }
#line 1601 "parser.c" /* yacc.c:1646  */
    break;

    case 23:
#line 140 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_VOID, NULL, NULL);
    }
#line 1607 "parser.c" /* yacc.c:1646  */
    break;

    case 24:
#line 143 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), NULL);
      (yyval.type)->arr_len = (yyvsp[-2].expr);
    }
#line 1613 "parser.c" /* yacc.c:1646  */
    break;

    case 25:
#line 145 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) =
          type_create(TYPE_FUNCTION, (yyvsp[-3].type), (yyvsp[-1].param_list));
    }
#line 1619 "parser.c" /* yacc.c:1646  */
    break;

    case 26:
#line 147 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL,
                                 (yyvsp[-1].stmt), NULL, NULL);
    }
#line 1625 "parser.c" /* yacc.c:1646  */
    break;

    case 27:
#line 148 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = NULL;
    }
#line 1631 "parser.c" /* yacc.c:1646  */
    break;

    case 28:
#line 151 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.param_list) = param_list_create(
          (yyvsp[-3].string), (yyvsp[-1].type), (yyvsp[0].param_list));
    }
#line 1637 "parser.c" /* yacc.c:1646  */
    break;

    case 29:
#line 152 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.param_list) = NULL;
    }
#line 1643 "parser.c" /* yacc.c:1646  */
    break;

    case 30:
#line 155 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = (yyvsp[0].type);
    }
#line 1649 "parser.c" /* yacc.c:1646  */
    break;

    case 31:
#line 156 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = (yyvsp[0].type);
    }
#line 1655 "parser.c" /* yacc.c:1646  */
    break;

    case 32:
#line 159 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), NULL);
    }
#line 1661 "parser.c" /* yacc.c:1646  */
    break;

    case 33:
#line 161 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.param_list) = param_list_create(
          (yyvsp[-3].string), (yyvsp[-1].type), (yyvsp[0].param_list));
    }
#line 1667 "parser.c" /* yacc.c:1646  */
    break;

    case 34:
#line 162 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.param_list) = NULL;
    }
#line 1673 "parser.c" /* yacc.c:1646  */
    break;

    case 35:
#line 165 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[-1].expr), NULL,
                                 NULL, NULL, NULL);
    }
#line 1679 "parser.c" /* yacc.c:1646  */
    break;

    case 36:
#line 166 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) =
          stmt_create(STMT_FOR, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr),
                      (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, NULL);
    }
#line 1685 "parser.c" /* yacc.c:1646  */
    break;

    case 37:
#line 167 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-2].expr),
                                 NULL, (yyvsp[0].stmt), NULL, NULL);
    }
#line 1691 "parser.c" /* yacc.c:1646  */
    break;

    case 38:
#line 168 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-4].expr),
                                 NULL, (yyvsp[-2].stmt), (yyvsp[0].stmt), NULL);
    }
#line 1697 "parser.c" /* yacc.c:1646  */
    break;

    case 39:
#line 169 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *lst =
          expr_create(EXPR_ARG, (yyvsp[-2].expr), (yyvsp[-1].expr));
      (yyval.stmt) =
          stmt_create(STMT_PRINT, NULL, NULL, lst, NULL, NULL, NULL, NULL);
    }
#line 1703 "parser.c" /* yacc.c:1646  */
    break;

    case 40:
#line 170 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) =
          stmt_create(STMT_PRINT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }
#line 1709 "parser.c" /* yacc.c:1646  */
    break;

    case 41:
#line 171 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[-1].expr),
                                 NULL, NULL, NULL, NULL);
    }
#line 1715 "parser.c" /* yacc.c:1646  */
    break;

    case 42:
#line 172 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), NULL, NULL, NULL,
                                 NULL, NULL, NULL);
    }
#line 1721 "parser.c" /* yacc.c:1646  */
    break;

    case 43:
#line 173 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL,
                                 (yyvsp[-1].stmt), NULL, NULL);
    }
#line 1727 "parser.c" /* yacc.c:1646  */
    break;

    case 44:
#line 176 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[-1].expr), NULL,
                                 NULL, NULL, NULL);
    }
#line 1733 "parser.c" /* yacc.c:1646  */
    break;

    case 45:
#line 177 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) =
          stmt_create(STMT_FOR, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr),
                      (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, NULL);
    }
#line 1739 "parser.c" /* yacc.c:1646  */
    break;

    case 46:
#line 178 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-4].expr),
                                 NULL, (yyvsp[-2].stmt), (yyvsp[0].stmt), NULL);
    }
#line 1745 "parser.c" /* yacc.c:1646  */
    break;

    case 47:
#line 179 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *lst =
          expr_create(EXPR_ARG, (yyvsp[-2].expr), (yyvsp[-1].expr));
      (yyval.stmt) =
          stmt_create(STMT_PRINT, NULL, NULL, lst, NULL, NULL, NULL, NULL);
    }
#line 1751 "parser.c" /* yacc.c:1646  */
    break;

    case 48:
#line 180 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) =
          stmt_create(STMT_PRINT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }
#line 1757 "parser.c" /* yacc.c:1646  */
    break;

    case 49:
#line 181 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[-1].expr),
                                 NULL, NULL, NULL, NULL);
    }
#line 1763 "parser.c" /* yacc.c:1646  */
    break;

    case 50:
#line 182 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), NULL, NULL, NULL,
                                 NULL, NULL, NULL);
    }
#line 1769 "parser.c" /* yacc.c:1646  */
    break;

    case 51:
#line 183 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL,
                                 (yyvsp[-1].stmt), NULL, NULL);
    }
#line 1775 "parser.c" /* yacc.c:1646  */
    break;

    case 52:
#line 186 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 1781 "parser.c" /* yacc.c:1646  */
    break;

    case 53:
#line 187 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 1787 "parser.c" /* yacc.c:1646  */
    break;

    case 54:
#line 190 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 1793 "parser.c" /* yacc.c:1646  */
    break;

    case 55:
#line 191 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 1799 "parser.c" /* yacc.c:1646  */
    break;

    case 56:
#line 194 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1805 "parser.c" /* yacc.c:1646  */
    break;

    case 57:
#line 195 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 1811 "parser.c" /* yacc.c:1646  */
    break;

    case 58:
#line 198 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) =
          expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1817 "parser.c" /* yacc.c:1646  */
    break;

    case 59:
#line 199 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1823 "parser.c" /* yacc.c:1646  */
    break;

    case 60:
#line 202 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1829 "parser.c" /* yacc.c:1646  */
    break;

    case 61:
#line 203 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1835 "parser.c" /* yacc.c:1646  */
    break;

    case 62:
#line 206 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1841 "parser.c" /* yacc.c:1646  */
    break;

    case 63:
#line 207 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1847 "parser.c" /* yacc.c:1646  */
    break;

    case 64:
#line 210 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1853 "parser.c" /* yacc.c:1646  */
    break;

    case 65:
#line 211 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1859 "parser.c" /* yacc.c:1646  */
    break;

    case 66:
#line 212 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1865 "parser.c" /* yacc.c:1646  */
    break;

    case 67:
#line 213 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1871 "parser.c" /* yacc.c:1646  */
    break;

    case 68:
#line 214 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1877 "parser.c" /* yacc.c:1646  */
    break;

    case 69:
#line 215 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_NE, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1883 "parser.c" /* yacc.c:1646  */
    break;

    case 70:
#line 216 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1889 "parser.c" /* yacc.c:1646  */
    break;

    case 71:
#line 219 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1895 "parser.c" /* yacc.c:1646  */
    break;

    case 72:
#line 220 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1901 "parser.c" /* yacc.c:1646  */
    break;

    case 73:
#line 221 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1907 "parser.c" /* yacc.c:1646  */
    break;

    case 74:
#line 224 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1913 "parser.c" /* yacc.c:1646  */
    break;

    case 75:
#line 225 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1919 "parser.c" /* yacc.c:1646  */
    break;

    case 76:
#line 226 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1925 "parser.c" /* yacc.c:1646  */
    break;

    case 77:
#line 227 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1931 "parser.c" /* yacc.c:1646  */
    break;

    case 78:
#line 230 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1937 "parser.c" /* yacc.c:1646  */
    break;

    case 79:
#line 231 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1943 "parser.c" /* yacc.c:1646  */
    break;

    case 80:
#line 234 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_NEG, NULL, (yyvsp[0].expr));
    }
#line 1949 "parser.c" /* yacc.c:1646  */
    break;

    case 81:
#line 235 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_POS, NULL, (yyvsp[0].expr));
    }
#line 1955 "parser.c" /* yacc.c:1646  */
    break;

    case 82:
#line 236 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_NOT, NULL, (yyvsp[0].expr));
    }
#line 1961 "parser.c" /* yacc.c:1646  */
    break;

    case 83:
#line 237 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1967 "parser.c" /* yacc.c:1646  */
    break;

    case 84:
#line 240 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_SELF_ADD, (yyvsp[-1].expr), NULL);
    }
#line 1973 "parser.c" /* yacc.c:1646  */
    break;

    case 85:
#line 241 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create(EXPR_SELF_SUB, (yyvsp[-1].expr), NULL);
    }
#line 1979 "parser.c" /* yacc.c:1646  */
    break;

    case 86:
#line 242 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 1985 "parser.c" /* yacc.c:1646  */
    break;

    case 87:
#line 245 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1991 "parser.c" /* yacc.c:1646  */
    break;

    case 88:
#line 246 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *name = expr_create_name((yyvsp[-4].string));
      struct expr *args =
          expr_create(EXPR_ARG, (yyvsp[-2].expr), (yyvsp[-1].expr));
      (yyval.expr) = expr_create(EXPR_CALL, name, args);
    }
#line 1997 "parser.c" /* yacc.c:1646  */
    break;

    case 89:
#line 247 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *name = expr_create_name((yyvsp[-2].string));
      (yyval.expr) = expr_create(EXPR_CALL, name, NULL);
    }
#line 2003 "parser.c" /* yacc.c:1646  */
    break;

    case 90:
#line 248 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_integer_literal((yyvsp[0].integer));
    }
#line 2009 "parser.c" /* yacc.c:1646  */
    break;

    case 91:
#line 249 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_float_literal((yyvsp[0].floating));
    }
#line 2015 "parser.c" /* yacc.c:1646  */
    break;

    case 92:
#line 250 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_char_literal((yyvsp[0].character));
    }
#line 2021 "parser.c" /* yacc.c:1646  */
    break;

    case 93:
#line 251 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_string_literal((yyvsp[0].string));
    }
#line 2027 "parser.c" /* yacc.c:1646  */
    break;

    case 94:
#line 252 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_boolean_literal(1);
    }
#line 2033 "parser.c" /* yacc.c:1646  */
    break;

    case 95:
#line 253 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_boolean_literal(0);
    }
#line 2039 "parser.c" /* yacc.c:1646  */
    break;

    case 96:
#line 254 "parser.bison" /* yacc.c:1646  */
    {
      struct expr *name = expr_create_name((yyvsp[-4].string));
      (yyvsp[-2].expr)->right = (yyvsp[0].expr);
      (yyval.expr) = expr_create(EXPR_SUBSCRIPT, name, (yyvsp[-2].expr));
    }
#line 2045 "parser.c" /* yacc.c:1646  */
    break;

    case 97:
#line 255 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = expr_create_name((yyvsp[0].string));
    }
#line 2051 "parser.c" /* yacc.c:1646  */
    break;

    case 98:
#line 258 "parser.bison" /* yacc.c:1646  */
    {
      (yyvsp[-1].expr)->right = (yyvsp[-3].expr);
      (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2057 "parser.c" /* yacc.c:1646  */
    break;

    case 99:
#line 259 "parser.bison" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 2063 "parser.c" /* yacc.c:1646  */
    break;

#line 2067 "parser.c" /* yacc.c:1646  */
    default:
      break;
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;

/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE(yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus) {
    ++yynerrs;
#if !YYERROR_VERBOSE
    yyerror(YY_("syntax error"));
#else
#define YYSYNTAX_ERROR yysyntax_error(&yymsg_alloc, &yymsg, yyssp, yytoken)
    {
      char const* yymsgp = YY_("syntax error");
      int yysyntax_error_status;
      yysyntax_error_status = YYSYNTAX_ERROR;
      if (yysyntax_error_status == 0)
        yymsgp = yymsg;
      else if (yysyntax_error_status == 1) {
        if (yymsg != yymsgbuf) YYSTACK_FREE(yymsg);
        yymsg = (char*)YYSTACK_ALLOC(yymsg_alloc);
        if (!yymsg) {
          yymsg = yymsgbuf;
          yymsg_alloc = sizeof yymsgbuf;
          yysyntax_error_status = 2;
        } else {
          yysyntax_error_status = YYSYNTAX_ERROR;
          yymsgp = yymsg;
        }
      }
      yyerror(yymsgp);
      if (yysyntax_error_status == 2) goto yyexhaustedlab;
    }
#undef YYSYNTAX_ERROR
#endif
  }

  if (yyerrstatus == 3) {
    /* If just tried and failed to reuse lookahead token after an
       error, discard it.  */

    if (yychar <= YYEOF) {
      /* Return failure if at end of input.  */
      if (yychar == YYEOF) YYABORT;
    } else {
      yydestruct("Error: discarding", yytoken, &yylval);
      yychar = YYEMPTY;
    }
  }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;

/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0) goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3; /* Each real token shifted decrements this.  */

  for (;;) {
    yyn = yypact[yystate];
    if (!yypact_value_is_default(yyn)) {
      yyn += YYTERROR;
      if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR) {
        yyn = yytable[yyn];
        if (0 < yyn) break;
      }
    }

    /* Pop the current state because it cannot handle the error token.  */
    if (yyssp == yyss) YYABORT;

    yydestruct("Error: popping", yystos[yystate], yyvsp);
    YYPOPSTACK(1);
    yystate = *yyssp;
    YY_STACK_PRINT(yyss, yyssp);
  }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Shift the error token.  */
  YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;

/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror(YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY) {
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = YYTRANSLATE(yychar);
    yydestruct("Cleanup: discarding lookahead", yytoken, &yylval);
  }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK(yylen);
  YY_STACK_PRINT(yyss, yyssp);
  while (yyssp != yyss) {
    yydestruct("Cleanup: popping", yystos[*yyssp], yyvsp);
    YYPOPSTACK(1);
  }
#ifndef yyoverflow
  if (yyss != yyssa) YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf) YYSTACK_FREE(yymsg);
#endif
  return yyresult;
}
#line 262 "parser.bison" /* yacc.c:1906  */

int yyerror(char *s) {
  printf("parse error: %s\n", s);
  return 1;
}
int yyparsemain(FILE *file) {
  yyin = file;
  yyparse();
  return 0;
}
int yyprintmain(FILE *file) {
  yyin = file;
  yyparse();
  if (!root) {
    yyerror("empty root node");
  }
  decl_print(root, 0);
  return 0;
}
int yyresolvemain(FILE *file) {
  yyin = file;
  yyparse();
  if (!root) {
    yyerror("empty root node");
  }
  decl_resolve(root);
  return RESOLVE_ERRORNEOUS;
}
