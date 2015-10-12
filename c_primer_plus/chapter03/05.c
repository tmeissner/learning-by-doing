#include <stdio.h>
#include <limits.h>



int main (void) {

  unsigned age;

  printf("Enter your age: ");
  scanf("%u", &age);

  if ((unsigned int)(UINT_MAX / 3.156e7) < age) {
    printf("Integer overflow\n");
    return 1;
  } else {
    printf("You are %u seconds old\n", (unsigned int)(age * 3.156e7));
  }

  return 0;

}
