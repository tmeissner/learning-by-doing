#include <stdio.h>
#include <string.h>



int main (void) {

  char first_name[20];

  printf("Your first name: ");
  scanf("%s", first_name);

  printf("Your name: \"%s\"\n", first_name);
  printf("Your name: \"%20s\"\n", first_name);
  printf("Your name: \"%*s\"\n", (int)(strlen(first_name)+3), first_name);

  return 0;

}
