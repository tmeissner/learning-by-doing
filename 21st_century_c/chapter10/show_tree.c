#include <stdio.h>
#include "process_dir.h"


void print_dir(filestruct in) {
  for (size_t i = 0; i < in.depth-1; ++i) {
    printf("    ");
  }
  printf("├ %s\n", in.name);
  for (size_t i = 0; i < in.depth-1; ++i) {
    printf("    ");
  }
  printf("└───┐\n");
}


void print_file(filestruct in) {
  for (size_t i = 0; i < in.depth; ++i) {
    printf("    ");
  }
  printf("│ %s\n", in.name);
}


int main (int argc, char **argv) {
  char *start = (argc > 1) ? argv[1] : ".";
  printf("Tree for %s:\n", start ? start : "the current directory");
  process_dir(.name=start, .file_action=print_file, .directory_action=print_dir);
}
