#include <stdio.h>
#include <float.h>


#define CM_PER_FEET 30.48
#define CM_PER_INCH 2.54


double getHeight(void);


int main (void) {

  double height;

  height = getHeight();

  while (height != 0) {
    unsigned feet = height / CM_PER_FEET;
    double inch = (height - feet * CM_PER_FEET) / CM_PER_INCH;
    printf("%.2f cm = %u feet, %.1f inches\n", height, feet, inch);
    height = getHeight();
  }

  printf("bye\n");

  return 0;

}


double getHeight(void) {

  double height;

  printf("Enter a height in centimeters (<=0 to quit): ");

  if (scanf("%lf", &height) != 1 || height <= 0) {
    height = 0;
  }

  return height;

}
