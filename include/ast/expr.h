#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
  EXPR_LIST,
  EXPR_ASSIGN,
  EXPR_OR,
  EXPR_AND,
  EXPR_LT,
  EXPR_LE,
  EXPR_GT,
  EXPR_GE,
  EXPR_EQ,
  EXPR_NE,
  EXPR_NEG,
  EXPR_POS,
  EXPR_NOT,
  EXPR_MOD,
  EXPR_SELF_ADD,
  EXPR_SELF_SUB,
  EXPR_EXP,
  EXPR_SUBSCRIPT,
  EXPR_ARG,
  EXPR_CALL,
  EXPR_NAME,
  EXPR_STRING_LITERAL,
  EXPR_INTEGER_LITERAL,
  EXPR_FLOAT_LITERAL,
  EXPR_CHAR_LITERAL,
  EXPR_BOOLEAN_LITERAL
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	int literal_value;
  float float_literal;
	const char *string_literal;
	struct symbol *symbol;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right);

struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_float_literal( float f );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_char_literal( char c );
struct expr * expr_create_string_literal( const char *str );

void expr_print( struct expr *e );

#endif
