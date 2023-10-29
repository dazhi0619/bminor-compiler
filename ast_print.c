#include "include/ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_indent(int level) {
  char* indent_string = (char *) malloc(level * 2 + 1);
  memset(indent_string, 32, level * 2);
  indent_string[level*2] = 0;
  return indent_string;
}

void decl_print(struct decl *d, int indent) {
  if (!d) return;
  char* indent_string = create_indent(indent);
  printf("%s", indent_string);
  printf("%s: ", d->name);
  type_print(d->type);
  if (d->value) {
    printf(" = ");
    expr_print(d->value);
    printf(";\n");
  } else if (d->code) {
    printf(" =\n", indent_string);
    stmt_print(d->code, indent);
    printf("%s\n", indent_string);
  } else {
    printf(";\n");
  }
  free(indent_string);
  if (d->next) decl_print(d->next, indent);
}

void expr_print(struct expr *e) {
  if (!e) return;
  if (e->kind == EXPR_LIST) {
    if (!e->left) printf("{");
  }
  if (e->left) {
    switch (e->kind) {
      case EXPR_NEG:
      case EXPR_NOT:
      case EXPR_POS:
      switch (e->left->kind) {
        case EXPR_EXP:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_EXP:
      switch (e->left->kind) {
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_MUL:
      case EXPR_DIV:
      case EXPR_MOD:
      switch (e->left->kind) {
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_ADD:
      case EXPR_SUB:
      switch (e->left->kind) {
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_LT:
      case EXPR_LE:
      case EXPR_GT:
      case EXPR_GE:
      case EXPR_EQ:
      case EXPR_NE:
      switch (e->left->kind) {
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
      }
      break;
      case EXPR_AND:
      switch (e->left->kind) {
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
      }
      break;
      case EXPR_OR:
      if (e->left->kind == EXPR_ASSIGN) {
        printf("(");
      }
      break;
      default:
      break;
    }
    expr_print(e->left);
  }
  if (e->left) {
    switch (e->kind) {
      case EXPR_NEG:
      case EXPR_NOT:
      case EXPR_POS:
      switch (e->left->kind) {
        case EXPR_EXP:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_EXP:
      switch (e->left->kind) {
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_MUL:
      case EXPR_DIV:
      case EXPR_MOD:
      switch (e->left->kind) {
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_ADD:
      case EXPR_SUB:
      switch (e->left->kind) {
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_LT:
      case EXPR_LE:
      case EXPR_GT:
      case EXPR_GE:
      case EXPR_EQ:
      case EXPR_NE:
      switch (e->left->kind) {
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
      }
      break;
      case EXPR_AND:
      switch (e->left->kind) {
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
      }
      break;
      case EXPR_OR:
      if (e->left->kind == EXPR_ASSIGN) {
        printf(")");
      }
      break;
      default:
      break;
    }
  }
  switch (e->kind) {
    case EXPR_ADD:
    printf("+"); break;
    case EXPR_SUB:
    printf("-"); break;
    case EXPR_MUL:
    printf("*"); break;
    case EXPR_DIV:
    printf("/"); break;
    case EXPR_LIST:
    if (e->left && e->right) printf(","); break;
    case EXPR_ASSIGN:
    printf("="); break;
    case EXPR_OR:
    printf("||"); break;
    case EXPR_AND:
    printf("&&"); break;
    case EXPR_LT:
    printf("<"); break;
    case EXPR_LE:
    printf("<="); break;
    case EXPR_GT:
    printf(">"); break;
    case EXPR_GE:
    printf(">="); break;
    case EXPR_EQ:
    printf("=="); break;
    case EXPR_NE:
    printf("!="); break;
    case EXPR_NEG:
    printf("-"); break;
    case EXPR_POS:
    printf("+"); break;
    case EXPR_NOT:
    printf("!"); break;
    case EXPR_MOD:
    printf("%"); break;
    case EXPR_SELF_ADD:
    printf("++"); break;
    case EXPR_SELF_SUB:
    printf("--"); break;
    case EXPR_EXP:
    printf("^"); break;
    case EXPR_SUBSCRIPT:
    printf("["); break;
    case EXPR_ARG:
    if (e->right) printf(", "); break;
    case EXPR_CALL:
    printf("("); break;
    default:
    break;
  }
  if (e->right) {
    switch (e->kind) {
      case EXPR_NEG:
      case EXPR_NOT:
      case EXPR_POS:
      switch (e->right->kind) {
      case EXPR_NEG:
      case EXPR_NOT:
      case EXPR_POS:
        case EXPR_EXP:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_EXP:
      switch (e->right->kind) {
      case EXPR_EXP:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_MUL:
      case EXPR_DIV:
      case EXPR_MOD:
      switch (e->right->kind) {
      case EXPR_MUL:
      case EXPR_DIV:
      case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_ADD:
      case EXPR_SUB:
      switch (e->right->kind) {
      case EXPR_ADD:
      case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
        }
      break;
      case EXPR_LT:
      case EXPR_LE:
      case EXPR_GT:
      case EXPR_GE:
      case EXPR_EQ:
      case EXPR_NE:
      switch (e->right->kind) {
      case EXPR_LT:
      case EXPR_LE:
      case EXPR_GT:
      case EXPR_GE:
      case EXPR_EQ:
      case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
      }
      break;
      case EXPR_AND:
      switch (e->right->kind) {
      case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf("(");
          break;
        default:
          break;
      }
      break;
      case EXPR_OR:
      if (e->right->kind == EXPR_ASSIGN) {
        printf("(");
      }
      break;
      default:
      break;
    }
    expr_print(e->right);
  }
  if (e->right) {
    switch (e->kind) {
      case EXPR_NEG:
      case EXPR_NOT:
      case EXPR_POS:
      switch (e->right->kind) {
      case EXPR_NEG:
      case EXPR_NOT:
      case EXPR_POS:
        case EXPR_EXP:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_EXP:
      switch (e->right->kind) {
      case EXPR_EXP:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_MUL:
      case EXPR_DIV:
      case EXPR_MOD:
      switch (e->right->kind) {
      case EXPR_MUL:
      case EXPR_DIV:
      case EXPR_MOD:
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_ADD:
      case EXPR_SUB:
      switch (e->right->kind) {
      case EXPR_ADD:
      case EXPR_SUB:
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
        }
      break;
      case EXPR_LT:
      case EXPR_LE:
      case EXPR_GT:
      case EXPR_GE:
      case EXPR_EQ:
      case EXPR_NE:
      switch (e->right->kind) {
      case EXPR_LT:
      case EXPR_LE:
      case EXPR_GT:
      case EXPR_GE:
      case EXPR_EQ:
      case EXPR_NE:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
      }
      break;
      case EXPR_AND:
      switch (e->right->kind) {
      case EXPR_AND:
        case EXPR_OR:
        case EXPR_ASSIGN:
          printf(")");
          break;
        default:
          break;
      }
      break;
      case EXPR_OR:
      if (e->right->kind == EXPR_ASSIGN) {
        printf(")");
      }
      break;
      default:
      break;
    }
  }
  switch (e->kind) {
    case EXPR_SUBSCRIPT:
    printf("]"); break;
    case EXPR_NAME:
    printf("%s", e->name); break;
    case EXPR_STRING_LITERAL:
    printf("\"%s\"", e->string_literal); break;
    case EXPR_INTEGER_LITERAL:
    printf("%d", e->literal_value); break;
    case EXPR_FLOAT_LITERAL:
    printf("%g", e->float_literal); break;
    case EXPR_CHAR_LITERAL:
    printf("\'%c\'", e->literal_value); break;
    case EXPR_BOOLEAN_LITERAL:
    if (e->literal_value) {
      printf("true");
    } else {
      printf("false");
    }
    break;
    default:
    break;
  }
  if (e->kind == EXPR_LIST) {
    if (!e->left) printf("}");
  }
}

void stmt_print(struct stmt* s, int indent) {
  if (!s) return;
  char* indent_string = create_indent(indent);
  switch (s->kind) {
    case STMT_DECL:
    decl_print(s->decl, indent); break;
    case STMT_EXPR:
    printf("%s", indent_string); expr_print(s->expr); printf(";\n"); break;
    case STMT_IF_ELSE:
    printf("%sif (", indent_string);
    expr_print(s->expr);
    printf(")\n");
    stmt_print(s->body, indent + 1);
    if (s->else_body) {
      printf("%selse\n", indent_string);
      stmt_print(s->else_body, indent + 1);
    }
    break;
    case STMT_FOR:
    printf("%sfor (", indent_string);
    expr_print(s->init_expr);
    printf("; ");
    expr_print(s->expr);
    printf("; ");
    expr_print(s->next_expr);
    printf(")\n");
    stmt_print(s->body, indent + 1);
    break;
    case STMT_PRINT:
    printf("%sprint", indent_string);
    if (s->expr) {
      printf(" ");
      expr_print(s->expr);
    }
    printf(";\n");
    break;
    case STMT_RETURN:
    printf("%sreturn", indent_string);
    if (s->expr) {
      printf(" ");
      expr_print(s->expr);
    }
    printf(";\n");
    break;
    case STMT_BLOCK:
    if (s->body) {
      printf("%s{\n", indent_string);
      stmt_print(s->body, indent + 1);
      printf("%s}\n", indent_string);
    }
    break;
  }
  free(indent_string);
  if (s->next) stmt_print(s->next, indent);
}

void type_print(struct type* t) {
  if (!t) return;
  switch (t->kind) {
    case TYPE_VOID:
    printf("void"); break;
    case TYPE_BOOLEAN:
    printf("boolean"); break;
    case TYPE_CHARACTER:
    printf("char"); break;
    case TYPE_INTEGER:
    printf("integer"); break;
    case TYPE_FLOAT:
    printf("float"); break;
    case TYPE_STRING:
    printf("string"); break;
    case TYPE_ARRAY:
    printf("array [%d] ", t->arr_len);
    type_print(t->subtype);
    break;
    case TYPE_FUNCTION:
    printf("function ");
    type_print(t->subtype);
    printf("(");
    param_list_print(t->params);
    printf(")");
    break;
    case TYPE_FUNCTION_ARRAY_PARAM:
    printf("array [] ");
    type_print(t->subtype);
    break;
  }
}

void param_list_print(struct param_list* p) {
  if (!p) return;
  printf("%s: ", p->name);
  type_print(p->type);
  if (p->next) {
    printf(", ");
    param_list_print(p->next);
  }
}
