#include <stdio.h>
#include <math.h>
#include <fenv.h>



double cubeNumber(double number);


int main (void) {

  double number;
  double cube_number;
  int    error = 0;

  printf("Give a number: ");

  if (scanf("%lf", &number) != 1 || isnan(number)) {
    printf("Not a number!\n");
    error = 1;
  } else {
    cube_number = cubeNumber(number);
    if (cube_number != NAN) {
      printf("%lf\n", cube_number);
    } else {
      printf("Floating point exception occured!\n");
      error = 1;
    }
  }

  return error;

}


double cubeNumber (double number) {

  double i;

  feclearexcept(FE_ALL_EXCEPT);

  i = pow(number, 3);

  if (fetestexcept(FE_ALL_EXCEPT) == 0) {
    i = NAN;
  }

  return i;

}
