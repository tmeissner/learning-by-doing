#include <stdio.h>



int main (void) {

  char first_name[20];
  char last_name[20];

  printf("Your first name: ");
  scanf("%s", first_name);
  printf("Your last name: ");
  scanf("%s", last_name);
  printf("Your name is %s, %s\n", last_name, first_name);

  return 0;

}
