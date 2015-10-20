#include <stdio.h>


#define CM_PER_INCH 2.54


int main (void) {

  float inches;

  printf("Enter your height in inches: ");
  scanf("%f", &inches);
  printf("Your height in cm is %.2f\n", inches * CM_PER_INCH);

  return 0;

}
