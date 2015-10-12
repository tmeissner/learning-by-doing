#include <stdio.h>



int main (void) {

  float quarts;

  printf("Enter a amount of water, in quarts: ");
  scanf("%f", &quarts);
  printf("Number of molecules: %e\n", quarts * 950.0 / 3.0e-23);

  return 0;

}
