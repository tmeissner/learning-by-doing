#include <stdio.h>



int main(void) {

  char letter = 'A';

  for (char i = 1; i <= 6; i++) {
    for (char j = letter; j < (letter + i); j++) {
      printf("%c", j);
    }
    letter += i;
    printf("\n");
  }

  return 0;

}
