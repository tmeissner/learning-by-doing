#include <stdio.h>
#include <limits.h>


#define SEC_PER_YEAR 3.156e7



int main (void) {

  unsigned age;

  printf("Enter your age: ");
  scanf("%u", &age);

  if ((unsigned int)(UINT_MAX / SEC_PER_YEAR) < age) {
    printf("Integer overflow\n");
    return 1;
  } else {
    printf("You are %u seconds old\n", (unsigned int)(age * SEC_PER_YEAR));
    return 0;
  }

}
