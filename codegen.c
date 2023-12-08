#include "include/codegen.h"

#include <stdio.h>
#include <stdlib.h>

#include "include/ast/expr.h"
#include "include/ast/stmt.h"
#include "include/ast/symbol.h"
#include "include/ast/type.h"

register_entry register_table[7] = {
    {"%rbx", false}, {"%r10", false}, {"%r11", false}, {"%r12", false},
    {"%r13", false}, {"%r14", false}, {"%r15", false},
};
const char *arg_name_table[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
int label_count = 0;
int arg_count = 0;

int scratch_alloc() {
  for (int i = 0; i < SCRACH_REGISTER_NUMBER; i++) {
    if (!register_table[i].inuse) {
      register_table[i].inuse = true;
      return i;
    }
  }
  printf("Error: Out of scratch registers.\n");
  exit(1);
}

void scratch_free(int r) {
  if (r < 0 || r >= 7) {
    printf(
        "Error: failed freeing scratch register %d: Invalid register number\n",
        r);
    exit(1);
  }
  register_table[r].inuse = false;
}

const char *scratch_name(int r) {
  if (r < 0 || r >= 7) {
    printf(
        "Error: failed retrieving the name of register %d: Invalid register "
        "number\n",
        r);
    exit(1);
  }
  return register_table[r].name;
}

void purge_scratch() {
  for (int i = 0; i < 7; i++) {
    register_table[i].inuse = false;
  }
}

int label_create() { return label_count++; }

const char *label_name(int label) {
  if (label < 0) {
    printf("Error: Invalid label\n");
    exit(1);
  }
  char *name = (char *)malloc(sizeof(char) * 10);
  sprintf(name, ".L%d", label);
  return name;
}

const char *string_label_name(int label) {
  if (label < 0) {
    printf("Error: Invalid label\n");
    exit(1);
  }
  char *name = (char *)malloc(sizeof(char) * 10);
  sprintf(name, "globl_string%d", label);
  return name;
}

const char *arg_reg(int arg) {
  if (0 <= arg && arg <= 5)
    return arg_name_table[arg];
  else {
    printf("Error: Invalid argument count");
    exit(1);
  }
}

const char *symbol_codegen(struct symbol *s) {
  if (!s) {
    printf("Error: Invalid symbol\n");
    return "";
  }
  if (s->kind == SYMBOL_GLOBAL) {
    return s->name;
  }

  int offset = s->which * 8;
  char *position = (char *)malloc(sizeof(char) * 10);
  sprintf(position, "-%d(%%rbp)", offset);
  return position;
}

void expr_codegen(FILE *fp, struct expr *e) {
  if (!e) return;
  if (e->kind != EXPR_ARG && e->kind != EXPR_SUBSCRIPT) {
    if (e->left) expr_codegen(fp, e->left);
    if (e->right) expr_codegen(fp, e->right);
  }
  int true_label, done_label, success_label, fail_label, extra_scratch;
  switch (e->kind) {
    case EXPR_NAME:
      e->reg = scratch_alloc();
      fprintf(fp, "MOVQ %s, %s\n", symbol_codegen(e->symbol),
              scratch_name(e->reg));
      break;
    case EXPR_ASSIGN:
      fprintf(fp, "MOVQ %s, %s\n", scratch_name(e->right->reg),
              scratch_name(e->left->reg));
      if (e->left->kind == EXPR_NAME) {
        fprintf(fp, "MOVQ %s, %s\n", scratch_name(e->left->reg),
                symbol_codegen(e->left->symbol));
      }
      e->reg = e->left->reg;
      scratch_free(e->right->reg);
      break;
    case EXPR_ADD:
      fprintf(fp, "ADDQ %s, %s\n", scratch_name(e->left->reg),
              scratch_name(e->right->reg));
      e->reg = e->right->reg;
      scratch_free(e->left->reg);
      break;
    case EXPR_SUB:
      fprintf(fp, "SUBQ %s, %s\n", scratch_name(e->right->reg),
              scratch_name(e->left->reg));
      e->reg = e->left->reg;
      scratch_free(e->right->reg);
      break;
    case EXPR_MUL:
      fprintf(fp, "MOVQ %s, %%rax\n", scratch_name(e->left->reg));
      fprintf(fp, "IMULQ %s\n", scratch_name(e->right->reg));
      fprintf(fp, "MOVQ %%rax, %s\n", scratch_name(e->right->reg));
      e->reg = e->right->reg;
      scratch_free(e->left->reg);
      break;
    case EXPR_DIV:
      fprintf(fp, "MOVQ %s, %%rax\n", scratch_name(e->left->reg));
      fprintf(fp, "CQO\n");
      fprintf(fp, "IDIVQ %s\n", scratch_name(e->right->reg));
      fprintf(fp, "MOVQ %%rax, %s\n", scratch_name(e->right->reg));
      e->reg = e->right->reg;
      scratch_free(e->left->reg);
      break;
    case EXPR_MOD:
      fprintf(fp, "MOVQ %s, %%rax\n", scratch_name(e->left->reg));
      fprintf(fp, "CQO\n");
      fprintf(fp, "IDIVQ %s\n", scratch_name(e->right->reg));
      fprintf(fp, "MOVQ %%rdx, %s\n", scratch_name(e->right->reg));
      e->reg = e->right->reg;
      scratch_free(e->left->reg);
      break;
    case EXPR_EXP:
      fprintf(fp, "MOVQ %s, %%rdi\n", scratch_name(e->left->reg));
      fprintf(fp, "MOVQ %s, %%rsi\n", scratch_name(e->right->reg));
      fprintf(fp, "CALL integer_power\n");
      e->reg = e->right->reg;
      fprintf(fp, "MOVQ %%rax, %s\n", scratch_name(e->reg));
      scratch_free(e->left->reg);
      break;
    case EXPR_EQ:
      true_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ %s, %s\n", scratch_name(e->left->reg),
              scratch_name(e->right->reg));
      fprintf(fp, "JE %s\n", label_name(true_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(true_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_GE:
      true_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ %s, %s\n", scratch_name(e->right->reg),
              scratch_name(e->left->reg));
      fprintf(fp, "JGE %s\n", label_name(true_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(true_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_LE:
      true_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ %s, %s\n", scratch_name(e->right->reg),
              scratch_name(e->left->reg));
      fprintf(fp, "JLE %s\n", label_name(true_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(true_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_GT:
      true_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ %s, %s\n", scratch_name(e->right->reg),
              scratch_name(e->left->reg));
      fprintf(fp, "JG %s\n", label_name(true_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(true_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_LT:
      true_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ %s, %s\n", scratch_name(e->right->reg),
              scratch_name(e->left->reg));
      fprintf(fp, "JL %s\n", label_name(true_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(true_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_NE:
      true_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ %s, %s\n", scratch_name(e->left->reg),
              scratch_name(e->right->reg));
      fprintf(fp, "JNE %s\n", label_name(true_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(true_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_AND:
      fail_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ $0, %s\n", scratch_name(e->left->reg));
      fprintf(fp, "JE %s\n", label_name(fail_label));
      fprintf(fp, "CMPQ $0, %s\n", scratch_name(e->right->reg));
      fprintf(fp, "JE %s\n", label_name(fail_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(fail_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_OR:
      success_label = label_create();
      done_label = label_create();
      e->reg = e->right->reg;
      fprintf(fp, "CMPQ $1, %s\n", scratch_name(e->left->reg));
      fprintf(fp, "JE %s\n", label_name(success_label));
      fprintf(fp, "CMPQ $1, %s\n", scratch_name(e->right->reg));
      fprintf(fp, "JE %s\n", label_name(success_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(success_label));
      fprintf(fp, "MOVQ $1, %s\n", scratch_name(e->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      scratch_free(e->left->reg);
      break;
    case EXPR_NOT:
      success_label = label_create();
      done_label = label_create();
      fprintf(fp, "CMP $0, %s\n", scratch_name(e->right->reg));
      fprintf(fp, "JE %s\n", label_name(success_label));
      fprintf(fp, "MOVQ $0, %s\n", scratch_name(e->right->reg));
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(success_label));
      fprintf(fp, "MOVQ $1, %s", scratch_name(e->right->reg));
      fprintf(fp, "%s:\n", label_name(done_label));
      break;
    case EXPR_POS:
      e->reg = e->right->reg;
      break;
    case EXPR_NEG:
      fprintf(fp, "MOVQ %s, %%rax\n", scratch_name(e->right->reg));
      fprintf(fp, "MOVQ $-1, %s\n", scratch_name(e->right->reg));
      fprintf(fp, "IMULQ %s\n", scratch_name(e->right->reg));
      fprintf(fp, "MOVQ %%rax, %s\n", scratch_name(e->right->reg));
      e->reg = e->right->reg;
      break;
    case EXPR_SELF_ADD:
      fprintf(fp, "ADDQ $1, %s\n", scratch_name(e->left->reg));
      if (e->left->kind == EXPR_NAME) {
        fprintf(fp, "MOVQ %s, %s\n", scratch_name(e->left->reg),
                symbol_codegen(e->left->symbol));
      }
      e->reg = e->left->reg;
      break;
    case EXPR_SELF_SUB:
      fprintf(fp, "SUBQ %s, $1\n", scratch_name(e->left->reg));
      if (e->left->kind == EXPR_NAME) {
        fprintf(fp, "MOVQ %s, %s\n", scratch_name(e->left->reg),
                symbol_codegen(e->left->symbol));
      }
      e->reg = e->left->reg;
      break;
    case EXPR_INTEGER_LITERAL:
    case EXPR_BOOLEAN_LITERAL:
    case EXPR_CHAR_LITERAL:
      e->reg = scratch_alloc();
      fprintf(fp, "MOVQ $%d, %s\n", e->literal_value, scratch_name(e->reg));
      break;
    case EXPR_STRING_LITERAL:
      fprintf(fp, ".data\n");
      e->string_label = label_create();
      fprintf(fp, "%s:  .string \"%s\"\n", string_label_name(e->string_label),
              e->string_literal);
      fprintf(fp, ".text\n");
      break;
    case EXPR_FLOAT_LITERAL:
      printf("Error: Floating point number not implemented\n");
      exit(1);
      break;
    case EXPR_CALL:
      fprintf(fp, "PUSHQ %%r10\n");
      fprintf(fp, "PUSHQ %%r11\n");
      fprintf(fp, "CALL %s\n", e->left->name);
      fprintf(fp, "POPQ %%r11\n");
      fprintf(fp, "POPQ %%r10\n");
      e->reg = scratch_alloc();
      fprintf(fp, "MOVQ %%rax, %s\n", scratch_name(e->reg));
      break;
    case EXPR_ARG:
      expr_codegen(fp, e->left);
      fprintf(fp, "MOVQ %s, %s\n", scratch_name(e->left->reg),
              arg_reg(arg_count++));
      scratch_free(e->left->reg);
      expr_codegen(fp, e->right);
      arg_count = 0;
      break;
    case EXPR_SUBSCRIPT:
      expr_codegen(fp, e->right);
      e->reg = scratch_alloc();
      extra_scratch = scratch_alloc();
      fprintf(fp, "LEAQ %s, %s\n", symbol_codegen(e->left->symbol),
              scratch_name(e->reg));
      fprintf(fp, "MOVQ $8, %s\n", scratch_name(extra_scratch));
      fprintf(fp, "MOVQ %s, %%rax\n", scratch_name(e->right->reg));
      fprintf(fp, "IMULQ %s\n", scratch_name(extra_scratch));
      fprintf(fp, "ADDQ %%rax, %s\n", scratch_name(e->reg));
      fprintf(fp, "MOVQ (%s), %s\n", scratch_name(e->reg),
              scratch_name(e->reg));
      scratch_free(e->right->reg);
      scratch_free(extra_scratch);
      break;
  }
}

void stmt_codegen(FILE *fp, struct stmt *s) {
  if (!s) return;
  int true_label, false_label, done_label, top_label;
  struct type *expr_type;
  struct expr *expr;
  switch (s->kind) {
    case STMT_EXPR:
      expr_codegen(fp, s->expr);
      scratch_free(s->expr->reg);
      break;
    case STMT_DECL:
      decl_codegen(fp, s->decl);
      break;
    case STMT_RETURN:
      if (!s->expr) break;
      expr_codegen(fp, s->expr);
      if (s->expr->kind == EXPR_STRING_LITERAL) {
        fprintf(fp, "MOVQ $%s, %%rax\n",
                string_label_name(s->expr->string_label));
      } else {
        fprintf(fp, "MOVQ %s, %%rax\n", scratch_name(s->expr->reg));
      }
      fprintf(fp, "POPQ %%r15\n");
      fprintf(fp, "POPQ %%r14\n");
      fprintf(fp, "POPQ %%r13\n");
      fprintf(fp, "POPQ %%r12\n");
      fprintf(fp, "POPQ %%rbx\n");
      fprintf(fp, "MOVQ %%rbp, %%rsp\n");
      fprintf(fp, "POPQ %%rbp\n");
      fprintf(fp, "RET\n");
      scratch_free(s->expr->reg);
      break;
    case STMT_IF_ELSE:
      false_label = label_create();
      done_label = label_create();
      expr_codegen(fp, s->expr);
      fprintf(fp, "CMPQ $0, %s\n", scratch_name(s->expr->reg));
      scratch_free(s->expr->reg);
      fprintf(fp, "JE %s\n", label_name(false_label));
      stmt_codegen(fp, s->body);
      fprintf(fp, "JMP %s\n", label_name(done_label));
      fprintf(fp, "%s:\n", label_name(false_label));
      stmt_codegen(fp, s->else_body);
      fprintf(fp, "%s:\n", label_name(done_label));
      break;
    case STMT_FOR:
      top_label = label_create();
      done_label = label_create();
      if (s->init_expr) {
        expr_codegen(fp, s->init_expr);
        scratch_free(s->init_expr->reg);
      }
      fprintf(fp, "%s:\n", label_name(top_label));
      if (s->expr) {
        expr_codegen(fp, s->expr);
        fprintf(fp, "CMPQ $0, %s\n", scratch_name(s->expr->reg));
        fprintf(fp, "JE %s\n", label_name(done_label));
        scratch_free(s->expr->reg);
      }
      stmt_codegen(fp, s->body);
      if (s->expr) {
        expr_codegen(fp, s->next_expr);
        scratch_free(s->next_expr->reg);
      }
      fprintf(fp, "JMP %s\n", label_name(top_label));
      fprintf(fp, "%s:\n", label_name(done_label));
      break;
    case STMT_PRINT:
      expr = s->expr;
      while (expr) {
        expr_codegen(fp, expr->left);
        if (expr->left->kind == EXPR_NAME) {
          if (expr->left->symbol->type->kind == TYPE_STRING &&
              expr->left->symbol->kind == SYMBOL_GLOBAL) {
            fprintf(fp, "MOVQ $%s, %%rdi\n",
                    symbol_codegen(expr->left->symbol));
          } else {
            fprintf(fp, "MOVQ %s, %%rdi\n", scratch_name(expr->left->reg));
          }
          switch (expr->left->symbol->type->kind) {
            case TYPE_STRING:
              fprintf(fp, "CALL print_string\n");
              break;
            case TYPE_CHARACTER:
              fprintf(fp, "CALL print_character\n");
              break;
            case TYPE_INTEGER:
              fprintf(fp, "CALL print_integer\n");
              break;
            case TYPE_BOOLEAN:
              fprintf(fp, "CALL print_boolean\n");
              break;
          }
        } else if (expr->left->kind == EXPR_STRING_LITERAL) {
          fprintf(fp, "MOVQ $%s, %%rdi\n",
                  string_label_name(expr->left->string_label));
        } else {
          fprintf(fp, "MOVQ %s, %%rdi\n", scratch_name(expr->left->reg));
        }
        if (expr->left->kind != EXPR_NAME) {
          struct type *t = expr_typecheck(expr->left);
          switch (t->kind) {
            case TYPE_STRING:
              fprintf(fp, "CALL print_string\n");
              break;
            case TYPE_CHARACTER:
              fprintf(fp, "CALL print_character\n");
              break;
            case TYPE_INTEGER:
              fprintf(fp, "CALL print_integer\n");
              break;
            case TYPE_BOOLEAN:
              fprintf(fp, "CALL print_boolean\n");
              break;
          }
        }
        scratch_free(expr->left->reg);
        expr = expr->right;
      }
      break;
    case STMT_BLOCK:
      stmt_codegen(fp, s->body);
      break;
  }
  stmt_codegen(fp, s->next);
}

void param_list_codegen(FILE *fp, struct param_list *p) {
  if (!p) return;
  unsigned int param_index = 0;
  while (p) {
    if (p->type->kind == TYPE_ARRAY) {
      printf("Error: Array not implemented\n");
      exit(1);
    }
    fprintf(fp, "PUSHQ %s\n", arg_reg(param_index++));
    p = p->next;
  }
}

void decl_codegen(FILE *fp, struct decl *d) {
  if (!d) return;
  if (d->type->kind == TYPE_FLOAT) {
    printf("Error: Floating point number not supported\n");
    exit(1);
  }
  switch (d->symbol->kind) {
    case SYMBOL_GLOBAL:
      fprintf(fp, ".globl %s\n", d->name);
      if (d->type->kind == TYPE_FUNCTION) {
        if (!d->code) break;
        fprintf(fp, "%s:\n", d->name);
        fprintf(fp, "PUSHQ %%rbp\n");
        fprintf(fp, "MOVQ %%rsp, %%rbp\n");
        param_list_codegen(fp, d->type->params);
        fprintf(fp, "PUSHQ %%rbx\n");
        fprintf(fp, "PUSHQ %%r12\n");
        fprintf(fp, "PUSHQ %%r13\n");
        fprintf(fp, "PUSHQ %%r14\n");
        fprintf(fp, "PUSHQ %%r15\n");
        stmt_codegen(fp, d->code);
        fprintf(fp, "POPQ %%r15\n");
        fprintf(fp, "POPQ %%r14\n");
        fprintf(fp, "POPQ %%r13\n");
        fprintf(fp, "POPQ %%r12\n");
        fprintf(fp, "POPQ %%rbx\n");
        fprintf(fp, "MOVQ %%rbp, %%rsp\n");
        fprintf(fp, "POPQ %%rbp\n");
        fprintf(fp, "RET\n");
        fprintf(fp, ".text\n");
      } else if (d->type->kind == TYPE_STRING) {
        fprintf(fp, ".data\n");
        fprintf(fp, "%s: .string \"%s\"\n", d->name, d->value->string_literal);
        fprintf(fp, ".text\n");
      } else if (d->type->kind == TYPE_ARRAY) {
        if (d->type->subtype->kind != TYPE_INTEGER) {
          printf("Error: Array not implemented\n");
          exit(1);
        }
        struct expr *e = d->value->right;
        if (e) {
          fprintf(fp, ".data\n");
          fprintf(fp, "%s:\n", d->name);
          fprintf(fp, ".quad %d", e->left->literal_value);
          e = e->right;
          while (e) {
            fprintf(fp, ", %d", e->left->literal_value);
            e = e->right;
          }
          fprintf(fp, "\n");
          fprintf(fp, ".text\n");
        }
      } else {
        fprintf(fp, ".data\n");
        if (d->value->kind == EXPR_NEG) {
          fprintf(fp, "%s: .quad -%d\n", d->name,
                  d->value->right->literal_value);
        } else if (d->value->kind == EXPR_POS) {
          fprintf(fp, "%s: .quad %d\n", d->name,
                  d->value->right->literal_value);
        } else {
          fprintf(fp, "%s: .quad %d\n", d->name, d->value->literal_value);
        }
        fprintf(fp, ".text\n");
      }
      break;
    case SYMBOL_LOCAL:
      if (d->type->kind == TYPE_STRING) {
        fprintf(fp, ".data\n");
        fprintf(fp, "%s:\n", d->name);
        fprintf(fp, ".string \"%s\"\n", d->value->string_literal);
        fprintf(fp, ".text\n");
        fprintf(fp, "MOVQ $%s, %s\n", d->name, symbol_codegen(d->symbol));
      } else if (d->type->kind == TYPE_ARRAY) {
        printf("Error: Array not implemented\n");
        exit(1);
      } else {
        if (d->value) {
          expr_codegen(fp, d->value);
          fprintf(fp, "MOVQ %s, %s\n", scratch_name(d->value->reg),
                  symbol_codegen(d->symbol));
          scratch_free(d->value->reg);
        }
      }
      break;
    default:
      break;
  }
  purge_scratch();
  decl_codegen(fp, d->next);
}
