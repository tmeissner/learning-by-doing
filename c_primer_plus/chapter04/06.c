#include <stdio.h>
#include <string.h>



int main (void) {

  char first_name[21];
  char last_name[21];

  printf("Give your first name: ");
  scanf("%20s", first_name);
  printf("Give your last name: ");
  scanf("%20s", last_name);
  printf("%s %s\n", first_name, last_name);
  printf("%*lu %*lu\n", (int)strlen(first_name), strlen(first_name), (int)strlen(last_name), strlen(last_name));
  printf("%s %s\n", first_name, last_name);
  printf("%-*lu %-*lu\n", (int)strlen(first_name), strlen(first_name), (int)strlen(last_name), strlen(last_name));

  return 0;

}
