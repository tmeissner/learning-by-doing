#include <stdio.h>
#include <limits.h>
#include <float.h>



int main (void) {

  int   a = INT_MAX;
  float b = FLT_MAX;

  // overflow
  printf("Integer overflow: %d\n", a+1);
  printf("Float overflow:   %f\n", b + 1.0);

  a = INT_MIN;
  b = -FLT_MAX;

  // underflow
  printf("Integer underflow: %d\n", a-1);
  printf("Float underflow:   %f\n", b-1.0);

  return 0;

}