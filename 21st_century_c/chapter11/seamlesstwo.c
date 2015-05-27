#include <stdio.h>
#include <math.h>



typedef struct point {
  double x, y;
} point;


/*
Nested the anonymous struct in anonymous union together with a named struct
to support direct access to 2D point in the 3D point structure.
*/
typedef struct {
  union {
    struct point;
    point p2;
  };
  double z;
} threepoint;


double length(point p) {
  return sqrt(p.x * p.x + p.y * p.y);
}

double threelength(threepoint p) {
  return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}


int main() {

  threepoint p = {.x = 3, .y = 0, .z = 4};
  printf("p is %g units from the origin\n", threelength(p));

  double xylength = length(p.p2);
  printf("Its projection onto the XY plane is %g units from the origin\n", xylength);

}
