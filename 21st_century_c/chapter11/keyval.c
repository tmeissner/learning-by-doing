#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "memory.h"
#include "keyval.h"



/*
Create a new key/value pair.
*/
keyval *keyval_new(char *key, void *value) {
  keyval *out = malloc(sizeof(keyval));
  if (out == NULL) {
    fprintf(stderr, "Out of memory.\n");
    abort();
  }
  *out = (keyval){.key = key, .value = value};
  return out;
}

/*
Copy a key/value pair. The new pair has pointers to
the values in the old pair, not copies of their data.
*/
keyval *keyval_copy(const keyval *in) {
  keyval *out = malloc(sizeof(keyval));
  if (out == NULL) {
    fprintf(stderr, "Out of memory.\n");
    abort();
  }
  *out = *in;
  return out;
}


/*
Free a existing key/value pair.
*/
void keyval_free(keyval *in) {
  safeFree(in);
}


/*
Check if key of key/value pair matches given key.
*/
int keyval_matches(const keyval *in, const char *key) {
  return !strcmp(in->key, key);
}
