#include <stdlib.h>



void saferFree(void **p) {
  if (p != NULL && *p != NULL) {
    free(*p);
    p = NULL;
  }
}
