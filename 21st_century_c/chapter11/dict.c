#include <stdio.h>
#include <stdlib.h>
#include "dict.h"



void *dictionary_not_found;


dictionary *dictionary_new(void) {

  static int dnf;
  if (!dictionary_not_found) {
    dictionary_not_found = &dnf;
  }
  dictionary *out = malloc(sizeof(dictionary));
  if(out != NULL) {
    *out = (dictionary) {};
  } else {
    fprintf(stderr, "Out of memory.\n");
    abort();
  }
  return out;

}


static void dictionary_add_keyval(dictionary *in, keyval *kv) {

  in->length++;
  keyval **tmp = realloc(in->pairs, sizeof(keyval*) * in->length);
  if(tmp != NULL) {
    in->pairs = tmp;
    tmp = NULL;
    in->pairs[in->length-1] = kv;
  } else {
    fprintf(stderr, "Out of memory.\n");
    abort();
  }

}


void dictionary_add(dictionary *in, char *key, void *value) {

  if(key == NULL) {
    fprintf(stderr, "NULL is not a valid key.\n");
    abort();
  }
  dictionary_add_keyval(in, keyval_new(key, value));

}


void *dictionary_find(const dictionary *in, const char *key) {

  for (size_t i = 0; i < in->length; i++) {
    if (keyval_matches(in->pairs[i], key)) {
      return in->pairs[i]->value;
    }
  }
  return dictionary_not_found;

}


dictionary *dictionary_copy(dictionary *in) {

  dictionary *out = dictionary_new();
  for (size_t i = 0; i < in->length; i++) {
    dictionary_add_keyval(out, keyval_copy(in->pairs[i]));
  }
  return out;

}


void dictionary_free(dictionary *in) {

  for (size_t i = 0; i < in->length; i++) {
    keyval_free(in->pairs[i]);
  }
  free(in->pairs);
  free(in);

}

