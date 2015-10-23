#include <stdio.h>
#include <string.h>



int main (void) {

  float height;
  char  name[21];

  printf("Give your heigth in cm: ");
  scanf("%f", &height);
  printf("Give your name: ");
  scanf("%20s", name);
  printf("%s, you are %.3f m tall\n", name, height/100);

  return 0;

}
