#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "include/encoder.h"
#include "include/parser.h"
#include "include/scanner.h"

int LINE_MAX =
    255 + 3;  // 3 is for 2 quotes and 1 terminator (return) in the input

int main(int argc, char *argv[]) {
  int argument;
  int option_index;
  static struct option long_options[] = {
      {"encode", required_argument, NULL, 0},
      {"scan", required_argument, NULL, 0},
      {"parse", required_argument, NULL, 0},
      {"print", required_argument, NULL, 0},
      {"resolve", required_argument, NULL, 0},
      {"typecheck", required_argument, NULL, 0},
      {"codegen", required_argument, NULL, 1}};
  argument = getopt_long_only(argc, argv, "", long_options, &option_index);

  FILE *file = NULL, *out = NULL;
  if (argument) {
    file = fopen(argv[2], "r");
    out = fopen(argv[3], "w");
    if (!file || !out) {
      printf("ERROR: Input or output file invalid.\n");
      return 1;
    }
  } else {
    file = fopen(optarg, "r");
    if (!file) {
      printf("ERROR: File invalid.\n");
      return 1;
    }
  }

  // Used for encoding and decoding
  char input[LINE_MAX];
  char decoded[LINE_MAX];
  char encoded[LINE_MAX];

  int ret = 0;
  switch (option_index) {
    case 0:
      if (!fgets(input, sizeof input, file)) {
        printf("ERROR: file content invalid.\n");
        return 1;
      }
      input[strcspn(input, "\n")] = 0;
      if (!string_decode(input, decoded)) {
        printf("ERROR: invalid string.\n");
        return 1;
      } else {
        string_encode(decoded, encoded);
        printf("%s", encoded);
        return 0;
      }

    case 1:
      return yyscanmain(file);

    case 2:
      return yyparsemain(file);

    case 3:
      return yyprintmain(file);

    case 4:
      return yyresolvemain(file);

    case 5:
      return yytypecheckmain(file);

    case 6:
      ret = yycodegenmain(file, out);
      fclose(out);
      return ret;

    default:
      printf("Illegal option!\n");
      return 1;
  }
}
