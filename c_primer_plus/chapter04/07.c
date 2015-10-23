#include <stdio.h>
#include <float.h>



int main (void) {


  float f_var = 1.0 / 3.0;
  double d_var = 1.0 / 3.0;

  printf("float: %18.4f double: %18.4g\n", f_var, d_var);
  printf("float: %18.12f double: %18.12g\n", f_var, d_var);
  printf("float: %.16f double: %.16g\n", f_var, d_var);
  printf("FLT_DIG: %16d DBL_DIG: %17d \n", FLT_DIG, DBL_DIG);

  return 0;

}
