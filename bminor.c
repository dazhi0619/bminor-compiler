#include "encoder.h"
#include <stdio.h>
#include <string.h>

int LINE_MAX = 258;

int main(int argc, char *argv[]) {
  if (argc == 3) {
    if (!strcmp(argv[1], "--encode")) {
      char *input_file_name = argv[2];
      FILE *file = fopen(input_file_name, "r");
      if (!file) {
        printf("ERROR: file invalid.\n");
        return 1;
      }
      char input[LINE_MAX];
      if (!fgets(input, sizeof input, file)) {
        printf("ERROR: file content invalid.\n");
        fclose(file);
        return 1;
      } else {
        fclose(file);
      }
      input[strcspn(input, "\n")] = 0;
      char decoded[LINE_MAX];
      char encoded[LINE_MAX];
      if (!string_decode(input, decoded)) {
        printf("ERROR: invalid string.\n");
        return 1;
      } else {
        string_encode(decoded, encoded);
        printf("%s", encoded);
        return 0;
      }
    } else {
      printf("ERROR: Unknown option %s\n", argv[1]);
      return 1;
    }
  } else {
    printf("ERROR: Expected 2 arguments. You have %d.\n", argc);
    return 1;
  }
}
