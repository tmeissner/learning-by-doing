#include <stdio.h>



int main (void) {

  float cups;

  printf("Give a volume in cups: ");
  scanf("%f", &cups);

  float pints = cups / 2;
  float ounces = cups * 8;
  float tablespoons = ounces * 2;
  float teaspoons = tablespoons * 3;

  printf("The given volume are %0.2f pints\n", pints);
  printf("The given volume are %0.2f ounces\n", ounces);
  printf("The given volume are %0.2f tablespoons\n", tablespoons);
  printf("The given volume are %0.2f teaspoons\n", teaspoons);

  return 0;

}
