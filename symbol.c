#include "include/ast.h"
#include "include/ast/stmt.h"
#include "include/ast/symbol.h"
#include "include/ast/type.h"
#include "include/hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int STACK_SIZE = 128;
const char* LOCAL_WHICH = "0";
const char* PARAM_WHICH = "1";

struct symbol *symbol_create(symbol_t kind, struct type *type, char *name) {
  struct symbol* s = (struct symbol*) malloc(sizeof(*s));
  s->kind = kind;
  s->type = type;
  s->name = name;
  s->defined = 0;
  s->which = 0;
  // printf("creating symbol %s with kind %d\n", name, kind);
  return s;
}

struct hash_table** stack_base = NULL;
struct hash_table** stack_top = NULL;

void scope_enter() {
  // printf("scope_enter!\n");
  if (!stack_base) {
    stack_base = (struct hash_table**) malloc(sizeof(*stack_base) * STACK_SIZE);
    stack_top = stack_base;
  }
  *stack_top = hash_table_create(0, 0);
  int* local_which = (int*) malloc(sizeof(int));
  *local_which = 0;
  hash_table_insert(*stack_top, LOCAL_WHICH, local_which);
  int* param_which = (int*) malloc(sizeof(int));
  *param_which = 0;
  hash_table_insert(*stack_top, PARAM_WHICH, param_which);
  stack_top++;
  // printf("scope_enter success.\n");
}
void scope_exit() {
  // printf("scoep_exit!\n");
  if (stack_top == stack_base) return;
  stack_top--;
  free(hash_table_lookup(*stack_top, LOCAL_WHICH));
  free(hash_table_lookup(*stack_top, PARAM_WHICH));
  hash_table_delete(*stack_top);
  // printf("scope_exit success.\n");
}
int scope_level() {
  return stack_top - stack_base;
}

void scope_bind(const char* name, struct symbol* sym) {
  // printf("scope_binding %s\n", name);
  if (scope_lookup_current(name) && (sym->type->kind != TYPE_FUNCTION || (sym->type->kind == TYPE_FUNCTION && sym->defined))) {
    printf("error: %s has already been defined in this scope.\n", name);
    return;
  }
  hash_table_insert(*(stack_top-1), name, sym);
  if (sym->kind == SYMBOL_LOCAL) {
    int* local_which = (int*) hash_table_lookup(*(stack_top-1), LOCAL_WHICH);
    *local_which = *local_which + 1;
    hash_table_insert(*(stack_top-1), LOCAL_WHICH, local_which);
    sym->which = *local_which;
  }
  if (sym->kind == SYMBOL_PARAM) {
    int* param_which = (int*) hash_table_lookup(*(stack_top-1), PARAM_WHICH);
    *param_which = *param_which + 1;
    hash_table_insert(*(stack_top-1), PARAM_WHICH, param_which);
    sym->which = *param_which;
  }
}
struct symbol *scope_lookup(const char* name) {
  for (struct hash_table** cur = stack_top - 1; cur != stack_base - 1; cur--) {
    char* key = NULL;
    void* value = NULL;
    hash_table_firstkey(*cur);
    while (hash_table_nextkey(*cur, &key, &value)) {
      struct symbol* sym = (struct symbol*) value;
      // printf("now iterating to %s\n", key);
      if (!strcmp(key, name)) {
        return sym;
      }
    }
  }
  return NULL;
}
struct symbol *scope_lookup_current(const char* name) {
  char* key;
  void* value;
  hash_table_firstkey(*(stack_top-1));
  while (hash_table_nextkey(*(stack_top-1), &key, &value)) {
    struct symbol* sym = (struct symbol*) value;
    if (!strcmp(key, name)) {
      return sym;
    }
  }
  return NULL;
}

void decl_resolve(struct decl* d) {
  if (!scope_level()) {
    scope_enter();
    if (scope_level() == 1 && !d) scope_exit();
  }
  if(!d) return;
  symbol_t kind = scope_level() > 1 ?
                  SYMBOL_LOCAL : SYMBOL_GLOBAL;
  d->symbol = symbol_create(kind,d->type,d->name);
  d->symbol->which = hash_table_size(*(stack_top-1)) + 1;
  expr_resolve(d->value);
  scope_bind(d->name,d->symbol);
  if(d->code) {
      d->symbol->defined = 1;
      scope_enter();
      param_list_resolve(d->type->params);
      stmt_resolve(d->code);
      scope_exit();
  }
  decl_resolve(d->next);
}

void expr_resolve(struct expr* e) {
  if(!e) return;
  if( e->kind==EXPR_NAME ) {
    e->symbol = scope_lookup(e->name);
    if (!e->symbol) {
      printf("resolve error: %s is not defined\n", e->name);
    } else {
      printf("%s resolves to ", e->name);
      switch (e->symbol->kind) {
        case SYMBOL_PARAM:
        printf("param %d", e->symbol->which); break;
        case SYMBOL_LOCAL:
        printf("local %d", e->symbol->which); break;
        case SYMBOL_GLOBAL:
        printf("global %s", e->symbol->name); break;
      }
      printf("\n");
    }
  } else {
    expr_resolve( e->left );
    expr_resolve( e->right );
  }
}

void stmt_resolve(struct stmt *s) {
  if (!s) return;
  switch(s->kind) {
    case STMT_DECL:
    decl_resolve(s->decl); break;
    case STMT_EXPR:
    expr_resolve(s->expr); break;
    case STMT_IF_ELSE:
      expr_resolve(s->expr);
    stmt_resolve(s->body);
    stmt_resolve(s->else_body);
    break;
    case STMT_FOR:
      expr_resolve(s->init_expr);
    expr_resolve(s->expr);
    expr_resolve(s->next_expr);
    stmt_resolve(s->body);
    break;
    case STMT_PRINT:
      expr_resolve(s->expr); break;
    case STMT_RETURN:
      expr_resolve(s->expr); break;
    case STMT_BLOCK:
      scope_enter();
    stmt_resolve(s->body);
    scope_exit();
    break;
  }
  stmt_resolve(s->next);
}

void param_list_resolve(struct param_list *p) {
  if (!p) return;
  symbol_t kind = SYMBOL_PARAM;
  p->symbol = symbol_create(kind,p->type,p->name);
  scope_bind(p->name,p->symbol);
  param_list_resolve(p->next);
}
