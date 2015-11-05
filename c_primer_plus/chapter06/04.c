#include <stdio.h>



int main(void) {

  unsigned char letter = 'A';

  for (unsigned char i = 0; i < 6; i++) {
    for (unsigned char j = letter; j <= (letter + i); j++) {
      printf("%c", j);
    }
    letter += (i + 1);
    printf("\n");
  }

  return 0;

}
