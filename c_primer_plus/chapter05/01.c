#include <stdio.h>



#define MIN_PER_HOUR 60


unsigned getMinutes(void);


int main (void) {

  unsigned min;

  min = getMinutes();

  while (min != 0) {
    printf("%u minutes are %u:%02u HH:MM\n", min, min/MIN_PER_HOUR, min % MIN_PER_HOUR);
    min = getMinutes();
  }

  return 0;

}


unsigned getMinutes(void) {

  unsigned min;

  printf("Time in minutes (0 to quit): ");

  if (scanf("%u", &min) != 1) {
    min = 0;
  }

  return min;

}
