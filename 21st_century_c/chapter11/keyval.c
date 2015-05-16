#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "keyval.h"



/*
Create a new key/value pair.
*/
keyval *keyval_new(char *key, void *value) {
  keyval *out = malloc(sizeof(keyval));
  if(out != NULL) {
    *out = (keyval){.key = key, .value = value};
  } else {
    fprintf(stderr, "Out of memory.\n");
    abort();
  }
  return out;
}

/*
Copy a key/value pair. The new pair has pointers to
the values in the old pair, not copies of their data.
*/
keyval *keyval_copy(const keyval *in) {
  keyval *out = malloc(sizeof(keyval));
  if(out != NULL) {
    *out = *in;
  } else {
    fprintf(stderr, "Out of memory.\n");
    abort();
  }
  return out;
}


/*
Free a existing key/value pair.
*/
void keyval_free(keyval *in) {
  if(in != NULL) {
    free(in);
  }
}


/*
Check if key of key/value pair matches given key.
*/
int keyval_matches(const keyval *in, const char *key) {
  return !strcasecmp(in->key, key);
}
