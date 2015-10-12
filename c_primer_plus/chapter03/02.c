#include <stdio.h>



int main (void) {

  unsigned int a;

  printf("Give an ASCII code value: ");
  scanf("%u", &a);

  if (a > 127) {
    printf("Outside of ASCII range\n");
    return 1;
  } else {
    printf("The character is: %c\n", a);
  }

  return 0;

}