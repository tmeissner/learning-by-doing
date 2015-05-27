void saferFree(void **p);

#define safeFree(p) saferFree((void **) &(p));
