#include <stdio.h>
#include <string.h>



int main (void) {

  float speed;
  float size;

  printf("Give download speed in Mbit/s: ");
  scanf("%f", &speed);
  printf("Give file size in Mbytes: ");
  scanf("%f", &size);
  printf("At %.2f megaits per second, a file of %.2f megabytes\n", speed, size);
  printf("downloads in %.2f seconds\n", size*8/speed);

  return 0;

}
