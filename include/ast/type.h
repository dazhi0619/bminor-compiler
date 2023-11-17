#ifndef TYPE_H
#define TYPE_H

struct param_list;
struct expr;

typedef enum {
  TYPE_VOID,
  TYPE_BOOLEAN,
  TYPE_CHARACTER,
  TYPE_INTEGER,
  TYPE_FLOAT,
  TYPE_STRING,
  TYPE_ARRAY,
  TYPE_FUNCTION,
} type_t;

struct type {
  type_t kind;
  struct param_list *params;
  struct type *subtype;
  struct expr *arr_len;
};

struct type *type_create(type_t kind, struct type *subtype,
                         struct param_list *params);
void type_print(struct type *t);

int type_equals(struct type *a, struct type *b);

struct type *type_copy(struct type *t);

void type_delete(struct type *t);

#endif
