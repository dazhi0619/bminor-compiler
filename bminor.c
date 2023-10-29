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
  static struct option long_options[] = {{"encode", required_argument, NULL, 0},
                                         {"scan", required_argument, NULL, 0},
                                         {"parse", required_argument, NULL, 0},
                                         {"print", required_argument, NULL, 0}};
  argument = getopt_long_only(argc, argv, "", long_options, &option_index);

  if (argument != 0) return 1;

  FILE *file = fopen(optarg, "r");
  if (!file) {
    printf("ERROR: file invalid.\n");
    return 1;
  }

  // Used for encoding and decoding
  char input[LINE_MAX];
  char decoded[LINE_MAX];
  char encoded[LINE_MAX];

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

    default:
      printf("Illegal option!\n");
      return 1;
  }
}
