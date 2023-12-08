#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdbool.h>

#include "ast.h"

#define SCRACH_REGISTER_NUMBER 7
#define XMM_NUMBER 9

typedef struct _register_entry {
  char *name;
  bool inuse;
} register_entry;

extern register_entry register_table[SCRACH_REGISTER_NUMBER];
extern register_entry xmm_table[XMM_NUMBER];
extern int codegen_result;
extern int label_count;
extern int arg_count;

int scratch_alloc();
void scratch_free(int r);
const char *scratch_name(int r);
void purge_scratch();
int xmm_alloc();
void xmm_free(int r);
const char *xmm_name(int r);
int label_create();
const char *label_name(int label);
const char *string_label_name(int label);
const char *arg_reg(int a);

const char *symbol_codegen(struct symbol *s);
void expr_codegen(FILE *fp, struct expr *e);
void stmt_codegen(FILE *fp, struct stmt *s);
void param_list_codegen(FILE *fp, struct param_list *p);
void decl_codegen(FILE *fp, struct decl *d);
#endif  // !CODEGEN_H
