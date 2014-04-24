// MinUnit test framework
// taken from http://www.jera.com/techinfo/jtns/jtn002.html
// slightly expanded, see http://stackoverflow.com/a/22732645

#include <errno.h>
#include <assert.h>

#define mu_assert(message, test) do {if (!(test)) return message;} while (0)
#define mu_run_test(test) do {char *message = test(); tests_run++; if (message) return message;} while (0)

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define assertf(A, M, ...) if(!(A)) {log_error(M, ##__VA_ARGS__); assert(A); }


extern int tests_run;