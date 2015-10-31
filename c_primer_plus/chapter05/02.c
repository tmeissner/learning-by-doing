#include <stdio.h>



int main (void) {

  int number;
  int i;

  printf("Give a number: ");

  if (scanf("%d", &number) != 1) {
    printf("Not a number!\n");
    return 1;
  }

  i = number;

  while (i <= number + 10) {
    printf("%d ", i++);
  }

  printf("\n");

  return 0;

}