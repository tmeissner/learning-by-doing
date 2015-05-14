#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct {
  char *name;
  int left, right, up, down;
} direction_s;


void this_row(direction_s d);
void draw_box(direction_s d);


int main() {

  direction_s D = {.name = "left", .left = 1};
  draw_box(D);

  // name is first, so we can omit label
  D = (direction_s) {"upper right", .up = 1, .right = 1};
  draw_box(D);

  // all struct elements set to zero
  draw_box((direction_s){});

}


void this_row(direction_s d) {

  char s[] = ".*.\n";

  if(d.left) {
    strlcpy(s, "*..\n", sizeof(s));
  } else if(d.right) {
    strlcpy(s, "..*\n", sizeof(s));
  }

  printf("%s", s);

}


void draw_box(direction_s d) {

  printf("%s:\n", (d.name ? d.name : "a box"));


  if(d.up) {
    this_row(d);
  } else {
    printf("...\n");
  }
  if(!d.up && !d.down) {
    this_row(d);
  } else {
    printf("...\n");
  }
  if(d.down) {
    this_row(d);
  } else {
    printf("...\n");
  }
  printf("\n");

}