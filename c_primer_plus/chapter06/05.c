#include <stdio.h>



int main(void) {

  char letter;

  printf("Give an uppercase char: ");
  scanf("%c", &letter);

  if (letter < 'A' || letter > 'Z') {
    printf("ERROR: No uppercase char\n");
    return 1;
  }

  for (char i = 'A'; i <= letter; i++) {
    for (char a = letter - i; a > 0; a--) {
      printf(" ");
    }
    for (char b = 'A'; b <= i ; b++) {
      printf("%c", b);
    }
    for (char c = i - 1; c >= 'A' ; c--) {
      printf("%c", c);
    }
    printf("\n");
  }

  return 0;

}
