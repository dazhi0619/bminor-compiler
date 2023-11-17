#include <stdlib.h>

#include "include/ast.h"

#define true 1
#define false 0

int TYPECHECK_ERRORNEOUS = 0;

int type_equals(struct type *a, struct type *b) {
  if (!a || !b) return false;

  if (a->kind == b->kind) {
    if (a->kind == TYPE_FUNCTION) {
      int error_collect = 0;
      if (!type_equals(a->subtype, b->subtype)) {
        printf("type error: mismatched function return type\n");
        TYPECHECK_ERRORNEOUS++;
        return false;
      }
      struct param_list *a_param, *b_param;
      a_param = a->params;
      b_param = b->params;
      int arg_count = 0;
      while (a_param && b_param) {
        arg_count += 1;
        if (!type_equals(a_param->type, b_param->type)) {
          printf("type error: mismatched param type\n");
          TYPECHECK_ERRORNEOUS++;
          return false;
        }
        a_param = a_param->next;
        b_param = b_param->next;
      }
      if ((!a_param && b_param) || (a_param && !b_param)) {
        printf("type error: mismatched param count\n");
        TYPECHECK_ERRORNEOUS++;
        return false;
      }
    } else if (a->kind == TYPE_ARRAY) {
      if (!type_equals(a->subtype, b->subtype) ||
          (!a->arr_len || !b->arr_len ||
           a->arr_len->literal_value != b->arr_len->literal_value)) {
        printf("type error: mismatched array type\n");
        return false;
      }
      return true;
    } else if (a->kind <= TYPE_STRING) {
      return true;
    } else {
      printf("type error: both types are unknown. Shouldn't reach here\n");
      TYPECHECK_ERRORNEOUS++;
      return false;
    }
  } else {
    return false;
  }
  return true;
}

struct type *type_copy(struct type *t) {
  if (!t) return NULL;
  struct type *copy_type;
  if (!(copy_type = (struct type *)malloc(sizeof(struct type)))) {
    printf("type error: type allocation failure when copying type\n");
    TYPECHECK_ERRORNEOUS++;
    return NULL;
  }

  copy_type->kind = t->kind;

  if (t->kind == TYPE_FUNCTION) {
    struct type *return_type = NULL;
    if (!(return_type = type_copy(t->subtype))) {
      free(copy_type);
      return NULL;
    }
    copy_type->subtype = return_type;

    copy_type->params = param_list_copy(t->params);

  } else if (t->kind == TYPE_ARRAY) {
    copy_type->subtype = type_copy(t->subtype);
    copy_type->arr_len = t->arr_len;
  } else if (t->kind > TYPE_FUNCTION) {
    printf("type error: unknown type to copy. Shouldn't reach here\n");
    TYPECHECK_ERRORNEOUS++;
    free(copy_type);
    return NULL;
  }

  return copy_type;
}

void type_delete(struct type *t) {
  if (!t) return;
  if (t->kind == TYPE_FUNCTION) {
    type_delete(t->subtype);
    param_list_delete(t->params);
  } else if (t->kind == TYPE_ARRAY) {
    type_delete(t->subtype);
    t->subtype = NULL;
  } else if (t->kind > TYPE_STRING) {
    printf(
        "type error: unknown type cannot be deleted. Shouldn't reach here\n");
    TYPECHECK_ERRORNEOUS++;
    return;
  }

  free(t);
}

struct param_list *param_list_copy(struct param_list *p) {
  if (!p) return NULL;
  struct param_list *copy;
  copy =
      param_list_create(p->name, type_copy(p->type), param_list_copy(p->next));
  return copy;
}

void param_list_delete(struct param_list *p) {
  if (!p) return;
  param_list_delete(p->next);

  type_delete(p->type);

  free(p);
}

struct type *expr_typecheck(struct expr *e) {
  if (!e) return NULL;

  struct type *lt = NULL;
  struct type *in;
  struct type *rt = NULL;

  if (e->kind != EXPR_LIST) lt = expr_typecheck(e->left);
  if (e->kind != EXPR_CALL && e->kind != EXPR_LIST)
    rt = expr_typecheck(e->right);

  struct type *result;

  struct type *first_type, *next_type;
  struct expr *next_expr;

  switch (e->kind) {
    case EXPR_ASSIGN:
      if (!type_equals(lt, rt)) {
        printf("type error: expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' Left hand side is of type ");
        type_print(lt);
        printf(" while right hand side is of type ");
        type_print(rt);
        printf("\n");
      } else {
        if (lt->kind == TYPE_ARRAY) {
          if (lt->subtype->kind == TYPE_FUNCTION ||
              lt->subtype->kind == TYPE_VOID) {
            printf("type error: Array cannot be of type ");
            TYPECHECK_ERRORNEOUS++;
            type_print(lt->subtype);
            printf("\n.");
          }
        }
      }

      if (lt->kind == TYPE_VOID) {
        printf("type error: Assignment in expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' is not allowed because left hand side is type 'void'\n");
        result = type_create(TYPE_INTEGER, NULL, NULL);
      } else {
        result = type_copy(lt);
      }
      break;
    case EXPR_OR:
    case EXPR_AND:
      if (!lt || !rt) break;
      if (!type_equals(lt, rt) || lt->kind != TYPE_BOOLEAN) {
        printf("type error: Arguments of logical expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' must be of type 'boolean'. Arguments are of type ");
        type_print(lt);
        printf(" and type ");
        type_print(rt);
        printf(" respectively.\n");
      }
      result = type_create(TYPE_BOOLEAN, NULL, NULL);
      break;
    case EXPR_LT:
    case EXPR_LE:
    case EXPR_GT:
    case EXPR_GE:
      if (!lt || !rt) break;
      if (!type_equals(lt, rt) ||
          (lt->kind != TYPE_FLOAT && lt->kind != TYPE_INTEGER)) {
        printf("type error: Arguments of comparison expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf(
            "' must be of type 'integer' or 'float'. Arguments are of type ");
        type_print(lt);
        printf(" and type ");
        type_print(rt);
        printf(" respectively.\n");
      }
      result = type_create(TYPE_BOOLEAN, NULL, NULL);
      break;
    case EXPR_EQ:
    case EXPR_NE:
      if (!lt || !rt) break;
      if (!type_equals(lt, rt)) {
        printf("type error: type mismatch");
        TYPECHECK_ERRORNEOUS++;
        printf("in comparing '");
        expr_print(e->left);
        printf("' and '");
        expr_print(e->right);
        printf("', which were of type ");
        type_print(lt);
        printf(" and type ");
        type_print(rt);
        printf(" respectively \n");
      }
      if (lt->kind != TYPE_INTEGER && lt->kind != TYPE_BOOLEAN &&
          lt->kind != TYPE_FLOAT && lt->kind != TYPE_CHARACTER) {
        printf("type error: Comparison between '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e->left);
        printf("' and '");
        expr_print(e->right);
        printf("' cannot be accomplished because ");
        type_print(lt);
        printf(" is a non-comparable type\n");
      }
      result = type_create(TYPE_BOOLEAN, NULL, NULL);
      break;
    case EXPR_ADD:
    case EXPR_SUB:
    case EXPR_MOD:
    case EXPR_MUL:
    case EXPR_DIV:
    case EXPR_EXP:
      if (!lt || !rt) break;
      if (!type_equals(lt, rt) ||
          (lt->kind != TYPE_FLOAT && lt->kind != TYPE_INTEGER)) {
        printf("type error: Arguments of expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf(
            "' must be of type 'integer' or 'float' at the same time. "
            "Arguments are of type ");
        type_print(lt);
        printf(" and type ");
        type_print(rt);
        printf(" respectively.\n");
      }
      result = type_create(TYPE_INTEGER, NULL, NULL);
      break;
    case EXPR_NEG:
      if (!rt) break;
      if (rt->kind != TYPE_INTEGER && rt->kind != TYPE_FLOAT) {
        printf("type error: Argument of expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' must be of type 'integer' or 'float'. Argument is of type ");
        type_print(rt);
        printf(".\n");
      }
      result = type_create(TYPE_INTEGER, NULL, NULL);
      break;
    case EXPR_NOT:
      if (!rt) break;
      if (rt->kind != TYPE_BOOLEAN) {
        printf("type error: Argument of expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' must be of type 'boolean'. Argument is of type ");
        type_print(lt);
        printf(".\n");
      }
      result = type_create(TYPE_BOOLEAN, NULL, NULL);
      break;
    case EXPR_SELF_ADD:
    case EXPR_SELF_SUB:
      if (!lt) break;
      if (lt->kind != TYPE_INTEGER) {
        printf("type error: Argument of expression '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' must be of type 'integer'. Argument is of type ");
        type_print(lt);
        printf(".\n");
      }
      result = type_create(TYPE_INTEGER, NULL, NULL);
      break;
    case EXPR_SUBSCRIPT:
      if (!lt || !rt) break;
      if (lt->kind == TYPE_ARRAY) {
        if (rt->kind != TYPE_INTEGER) {
          printf("type error: array subscription at '");
          TYPECHECK_ERRORNEOUS++;
          expr_print(e);
          printf("' has non-integer index\n");
          printf("\tindex was of type ");
          type_print(rt);
          printf("\n");
        }

        result = type_copy(lt->subtype);
      } else {
        printf("type error: variables of type ");
        TYPECHECK_ERRORNEOUS++;
        type_print(lt);
        printf(" in '");
        expr_print(e);
        printf("' do not support subscription\n");
        result = type_copy(lt);
      }
      break;
    case EXPR_CALL:
      if (!lt) break;
      if (lt->kind == TYPE_FUNCTION) {
        next_expr = e->right;
        struct type *t;
        struct param_list *pl = lt->params;
        int arg_counter = 1;
        while (next_expr && pl) {
          t = expr_typecheck(next_expr->left);
          if (!type_equals(t, pl->type)) {
            printf("type error: expected argument %i of ", arg_counter);
            TYPECHECK_ERRORNEOUS++;
            expr_print(next_expr->left);
            printf(" to be type ");
            type_print(pl->type);
            printf(". Argument %i was of type ", arg_counter);
            type_print(t);
            printf(".\n");
          }
          type_delete(t);
          next_expr = next_expr->right;
          pl = pl->next;
          arg_counter++;
        }

        arg_counter--;
        if (next_expr && next_expr->left && !pl) {
          printf("type error: Too many arguments provided to ");
          TYPECHECK_ERRORNEOUS++;
          expr_print(e->left);
          printf(". This function requires %i argumnets.", arg_counter);
        } else if ((!next_expr || next_expr && !next_expr->left) && pl) {
          printf("type error: Too few arguments provided to ");
          TYPECHECK_ERRORNEOUS++;
          expr_print(e->left);
          while (pl) {
            arg_counter++;
            pl = pl->next;
          }
          printf(". This function requires %i arguments.\n", arg_counter);
        }
      } else {
        printf("type error: '");
        expr_print(e);
        printf("' does not call a known function\n");
      }
      result = type_copy(lt->subtype);
      break;
    case EXPR_NAME:
      if (e->symbol) {
        result = type_copy(e->symbol->type);
      } else {
        printf("type error: identifier '");
        TYPECHECK_ERRORNEOUS++;
        expr_print(e);
        printf("' did not resolve to known value\n");
        result = NULL;
      }
      break;
    case EXPR_INTEGER_LITERAL:
      result = type_create(TYPE_INTEGER, NULL, NULL);
      break;
    case EXPR_BOOLEAN_LITERAL:
      result = type_create(TYPE_BOOLEAN, NULL, NULL);
      break;
    case EXPR_CHAR_LITERAL:
      result = type_create(TYPE_CHARACTER, NULL, NULL);
      break;
    case EXPR_STRING_LITERAL:
      result = type_create(TYPE_STRING, NULL, NULL);
      break;
    case EXPR_LIST:
      if (!e->right->left) {
        printf("type error: empty array\n");
        result = type_create(TYPE_VOID, NULL, NULL);
      } else {
        first_type = expr_typecheck(e->right->left);
        result = type_create(TYPE_ARRAY, first_type, NULL);
      }

      struct expr *next_expr = e->right->right;
      int elem_counter = 0;
      while (next_expr) {
        if ((next_type = expr_typecheck(next_expr->left))) {
          if (!type_equals(first_type, next_type)) {
            printf("type error: the types of the array elements don't match. ");
            TYPECHECK_ERRORNEOUS++;
            printf("Initial element is of type ");
            type_print(first_type);
            printf(" and element %i is of type ", elem_counter);
            type_print(next_type);
            printf(".\n");
          }
          next_expr = next_expr->right;
          type_delete(next_type);
          elem_counter++;
        }
      }

      result->arr_len = expr_create_integer_literal(++elem_counter);
      break;
    case EXPR_ARG:
      printf(
          "type eorror: arguments without function call. Shouldn't reach "
          "here\n");
      result = type_create(TYPE_VOID, NULL, NULL);
      break;
    default:
      printf("type error: Cannot type check unknown type at expression '");
      TYPECHECK_ERRORNEOUS++;
      expr_print(e);
      printf("'. Shouldn't reach here\n");
      result = NULL;
      break;
  }

  type_delete(lt);
  type_delete(rt);

  return result;
}

type_t return_type = 0;
void decl_typecheck(struct decl *d) {
  if (!d) return;
  if (!d->type) {
    printf("d->type is null. Shouldn't reach here\n");
  }
  if (d->type && d->type->kind == TYPE_FUNCTION) {
    if (d->symbol && d->symbol->type && d->type) {
      if (d->symbol->type->subtype->kind == TYPE_FUNCTION ||
          d->symbol->type->subtype->kind == TYPE_ARRAY) {
        printf("type error: Function %s cannot return type ", d->name);
        TYPECHECK_ERRORNEOUS++;
        type_print(d->symbol->type->subtype);
        printf(".\n");
      }
    } else {
      printf(
          "type error: unable to determine original return type of function "
          "%s. Shouldn't reach here\n",
          d->name);
      TYPECHECK_ERRORNEOUS++;
    }
  }

  if (d->value) {
    struct type *t;
    t = expr_typecheck(d->value);
    if (!d->symbol) {
      printf("d->symbol is null. Shouldn't reach here\n");
    }
    if (!type_equals(t, d->symbol->type)) {
      printf("type error: cannot initialize a value of type ");
      TYPECHECK_ERRORNEOUS++;
      type_print(d->symbol->type);
      printf(" with a value of type ");
      type_print(t);
      printf(".\n");
    }
    type_delete(t);
  }
  if (d->code) {
    return_type = d->symbol->type->subtype->kind;
    stmt_typecheck(d->code);
    return_type = 0;
  }
  decl_typecheck(d->next);
}

void print_kind(type_t kind) {
  switch (kind) {
    case TYPE_VOID:
      printf("void");
      break;
    case TYPE_BOOLEAN:
      printf("boolean");
      break;
    case TYPE_CHARACTER:
      printf("char");
      break;
    case TYPE_INTEGER:
      printf("integer");
      break;
    case TYPE_FLOAT:
      printf("float");
      break;
    case TYPE_STRING:
      printf("string");
      break;
    case TYPE_ARRAY:
      printf("array");
      break;
    case TYPE_FUNCTION:
      printf("function");
      break;
  }
}

void stmt_typecheck(struct stmt *s) {
  if (!s) return;
  struct type *t;
  struct expr *e;

  switch (s->kind) {
    case STMT_DECL:
      decl_typecheck(s->decl);
      break;
    case STMT_EXPR:
      if ((t = expr_typecheck(s->expr))) type_delete(t);
      break;
    case STMT_IF_ELSE:
      t = expr_typecheck(s->expr);
      if (t->kind != TYPE_BOOLEAN) {
        printf("type error: if statements must have boolean expressions.");
        TYPECHECK_ERRORNEOUS++;
        printf("Current control expression is of type ");
        type_print(t);
        printf("\n");
      }
      type_delete(t);
      stmt_typecheck(s->body);
      stmt_typecheck(s->else_body);
      break;
    case STMT_FOR:
      t = expr_typecheck(s->init_expr);
      type_delete(t);
      t = expr_typecheck(s->expr);
      if (t && t->kind != TYPE_BOOLEAN) {
        printf("type error: Condition of for loop must be of type 'boolean'");
        TYPECHECK_ERRORNEOUS++;
        printf("Current condition is of type ");
        type_print(t);
        printf("\n");
      }
      type_delete(t);
      t = expr_typecheck(s->next_expr);
      type_delete(t);
      stmt_typecheck(s->body);
      break;
    case STMT_PRINT:
      e = s->expr;
      while (e && e->left) {
        t = expr_typecheck(e->left);
        type_delete(t);
        e = e->right;
      }
      break;
    case STMT_RETURN:
      t = expr_typecheck(s->expr);
      if (t->kind != return_type) {
        printf("type error: Current function scope has return type ");
        TYPECHECK_ERRORNEOUS++;
        print_kind(return_type);
        printf(" but expression returned (");
        expr_print(s->expr);
        printf(") has type ");
        type_print(t);
        printf(".\n");
      }
      type_delete(t);
      if (s->expr->left && s->expr->right && s->expr->right->left) {
        printf("type error: function cannot return multiple expressions\n");
        TYPECHECK_ERRORNEOUS++;
      }
      break;
    case STMT_BLOCK:
      stmt_typecheck(s->body);
      break;
    default:
      printf(
          "type error: unknown statement type detected. Shouln't reach here\n");
      TYPECHECK_ERRORNEOUS++;
      break;
  }

  stmt_typecheck(s->next);
}
