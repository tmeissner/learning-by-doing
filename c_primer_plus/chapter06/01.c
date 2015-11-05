#include <stdio.h>



int main(void) {

  unsigned char abc [26];

  for (size_t i = 'a'; i <= 'z'; i++) {
    abc[i - 'a'] = i;
  }

  for (size_t i = 0; i < sizeof(abc); i++) {
    printf("%c", abc[i]);
  }

  printf("\n");

  return 0;

}
