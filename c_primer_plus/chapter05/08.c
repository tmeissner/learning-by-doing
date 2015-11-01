#include <stdio.h>
#include <limits.h>
#include <stdbool.h>



int getNumber(char * s, bool *error);


int main(void) {

  int first_operand;
  int second_operand;
  bool first_error;
  bool second_error;

  printf("This program computes moduli.\n");

  second_operand = getNumber("Enter an integer to serve as the second operand: ", &second_error);
  first_operand  = getNumber("Now enter the first operand: ", &first_error);

  do {
    printf("%d %% %d is %d\n", first_operand, second_operand, first_operand % second_operand);
    first_operand  = getNumber("Now enter the first operand (<= 0 to quit): ", &first_error);
  } while (!first_error && !second_error);

  return 0;

}


int getNumber(char * s, bool *error) {

  int number;

  *error = false;

  printf("%s", s);

  if (!scanf("%d", &number) || number < 0) {
    *error = true;
  }

  return number;

}
