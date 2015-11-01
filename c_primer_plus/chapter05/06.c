#include <stdio.h>
#include <limits.h>



int getNumber(void);


int main(void) {

  int count = 0;
  int sum   = 0;
  int end   = getNumber();

  if (end >= 0) {

    while (count++ < end) {
      if (INT_MAX / count < count || (INT_MAX - sum) < count * count) {
        printf("Integer overflow\n");
        return 1;
      } else {
        sum = sum + count * count;
      }
    }

    printf("sum = %d\n", sum);

  }

  return 0;

}


int getNumber(void) {

  int number;

  printf("How far should we add: ");

  if (!scanf("%d", &number)  || number < 0) {
    number = -1;
  }

  return number;

}
