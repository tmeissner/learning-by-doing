#include <stdio.h>
#include <string.h>



int main (void) {

  float number;

  printf("Give a float number: ");
  scanf("%g", &number);
  printf("The input is %.1f or %.1e\n", number, number);
  printf("The input is %+.3f or %.3e\n", number, number);

  return 0;

}
