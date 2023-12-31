#ifndef DECL_H
#define DECL_H

#include <stdio.h>

struct type;
struct expr;
struct stmt;
struct symbol;
struct decl;

struct decl {
  char *name;
  struct type *type;
  struct expr *value;
  struct stmt *code;
  struct symbol *symbol;
  struct decl *next;
};

struct decl *decl_create(char *name, struct type *type, struct expr *value,
                         struct stmt *code, struct decl *next);
void decl_print(struct decl *d, int indent);
void decl_typecheck(struct decl *d);

#endif
