#include <stdio.h>


#define LITERS_PER_GALLON 3.786
#define KM_PER_MILE 1.609


int main (void) {

  float miles;
  float gallons;

  printf("Miles traveled: ");
  scanf("%f", &miles);
  printf("gasoline gallons: ");
  scanf("%f", &gallons);

  printf("Miles per gallon: %.1f\n", miles / gallons);
  printf("Liters per 100km: %.1f\n", (gallons * LITERS_PER_GALLON)/(miles * KM_PER_MILE));

  return 0;

}
