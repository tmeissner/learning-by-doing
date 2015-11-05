#include <stdio.h>



int main(void) {

  for (int i = 0; i < 6; i++) {
    for (int j = 'F'; j >= ('F'-i); j--) {
      printf("%c", j);
    }
    printf("\n");
  }

  return 0;

}
