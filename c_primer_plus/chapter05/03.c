#include <stdio.h>



#define DAYS_PER_WEEK 7


unsigned getDays(void);


int main (void) {

  int days;

  days = getDays();

  while (days != 0) {
    printf("%d days are %d weeks, %d days\n", days, days / DAYS_PER_WEEK, days % DAYS_PER_WEEK);
    days = getDays();
  }

  return 0;

}


unsigned getDays(void) {

  int days;

  printf("Number of days (<=0 to quit): ");

  if (scanf("%d", &days) != 1 || days <= 0) {
    days = 0;
  }

  return days;

}
