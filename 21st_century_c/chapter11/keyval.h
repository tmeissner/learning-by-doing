typedef struct keyval {
  char *key;
  void *value;
} keyval;


keyval *keyval_new(char *key, void *value);
keyval *keyval_copy(const keyval *in);
void keyval_free(keyval *in);
int keyval_matches(const keyval *in, const char *key);
