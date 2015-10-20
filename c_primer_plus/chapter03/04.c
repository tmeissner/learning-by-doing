#include <stdio.h>



int main (void) {

  float a;

  printf("Enter a floating-point value: ");
  scanf("%f", &a);
  printf("fixed-point notation: %.2f\n", a);
  printf("exponential notation: %.2e\n", a);
  printf("p notation: %.2a\n", a);

  return 0;

}
