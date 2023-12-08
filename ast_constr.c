#include <stdlib.h>

#include "include/ast.h"

struct decl *decl_create(char *name, struct type *type, struct expr *value,
                         struct stmt *code, struct decl *next) {
  struct decl *d = (struct decl *)calloc(1, sizeof(*d));
  d->name = name;
  d->type = type;
  d->value = value;
  d->code = code;
  d->next = next;
  return d;
}

struct stmt *stmt_create(stmt_t kind, struct decl *decl, struct expr *init_expr,
                         struct expr *expr, struct expr *next_expr,
                         struct stmt *body, struct stmt *else_body,
                         struct stmt *next) {
  struct stmt *s = (struct stmt *)malloc(sizeof(*s));
  s->kind = kind;
  s->decl = decl;
  s->init_expr = init_expr;
  s->expr = expr;
  s->next_expr = next_expr;
  s->body = body;
  s->else_body = else_body;
  s->next = next;
  return s;
}

struct expr *expr_create(expr_t kind, struct expr *L, struct expr *R) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = kind;
  e->left = L;
  e->right = R;
  e->reg = -1;
  e->string_label = -1;
  return e;
}

struct expr *expr_create_name(const char *name) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = EXPR_NAME;
  e->name = name;
  return e;
}

struct expr *expr_create_integer_literal(int i) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = EXPR_INTEGER_LITERAL;
  e->literal_value = i;
  return e;
}

struct expr *expr_create_float_literal(float f) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = EXPR_FLOAT_LITERAL;
  e->float_literal = f;
  return e;
}

struct expr *expr_create_boolean_literal(int b) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = EXPR_BOOLEAN_LITERAL;
  e->literal_value = b;
  return e;
}

struct expr *expr_create_char_literal(char c) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = EXPR_CHAR_LITERAL;
  e->literal_value = c;
  return e;
}

struct expr *expr_create_string_literal(const char *str) {
  struct expr *e = (struct expr *)calloc(1, sizeof(*e));
  e->kind = EXPR_STRING_LITERAL;
  e->string_literal = str;
  return e;
}

struct type *type_create(type_t kind, struct type *subtype,
                         struct param_list *params) {
  struct type *t = (struct type *)calloc(1, sizeof(*t));
  t->kind = kind;
  t->subtype = subtype;
  t->params = params;
  t->arr_len = NULL;
  return t;
}

struct param_list *param_list_create(char *name, struct type *type,
                                     struct param_list *next) {
  struct param_list *p = (struct param_list *)malloc(sizeof(*p));
  p->name = name;
  p->type = type;
  p->next = next;
  return p;
}
