#include <stdio.h>


#define MOL_MASS 3.0e-23
#define WATER_QUART_GRAM 950.0


int main (void) {

  float quarts;

  printf("Enter a amount of water, in quarts: ");
  scanf("%f", &quarts);
  printf("Number of molecules: %.2e\n", quarts * WATER_QUART_GRAM / MOL_MASS);

  return 0;

}
