void RuntimeError(const char *m, int p,
                  const char *f, int l);


#define RUNTIME_ERROR(description, parameter) \
  RuntimeError(description, parameter, __FILE__, __LINE__)