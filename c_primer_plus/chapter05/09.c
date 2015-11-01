#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>



double getNumber(char * s);
void calcTemperatures(double fahrenheit);


int main(void) {

  double fahrenheit;

  printf("This program calculates Celsius & Kelvin from Fahrenheit.\n");
  fahrenheit  = getNumber("Now enter the temp in Fahrenheit: ");

  while (!isnan(fahrenheit)) {
    calcTemperatures(fahrenheit);
    fahrenheit  = getNumber("Now enter the first operand (q to quit): ");
  };

  return 0;

}


double getNumber(char * s) {

  double number;

  printf("%s", s);

  if (!scanf("%lf", &number) || isnan(number)) {
    number = NAN;
  }

  return number;

}


void calcTemperatures(double fahrenheit) {

  const float celsius_div    = 5.0 / 9.0;
  const float celsius_offset = 32.0;
  const float kelvin_offset  = 273.16;

  const double celsius = celsius_div *(fahrenheit - celsius_offset);
  const double kelvin  = celsius + kelvin_offset;

  printf("%.2lf Fahrenheit are %.2lf Celsius or %.2lf Kelvin.\n", fahrenheit, celsius, kelvin);

}
