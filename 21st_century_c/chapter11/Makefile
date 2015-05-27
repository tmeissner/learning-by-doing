CFLAGS = -Wall -Wextra --std=c11 -g -lm -ftest-coverage -fprofile-arcs

.PHONY : all
all : simple_cplx seamlessone seamlesstwo dict_use


simple_cplx : cplx.h complex.c simple_cplx.c
	$(CC) `pkg-config --cflags --libs gsl` $(CFLAGS) complex.c $@.c -o $@

seamlessone : seamlessone.c
	$(CC) $(CFLAGS) -fms-extensions -Wno-microsoft $@.c -o $@

seamlesstwo : seamlesstwo.c
	$(CC) $(CFLAGS) -fms-extensions -Wno-microsoft $@.c -o $@

dict_use : memory.h memory.c keyval.h keyval.c dict.h dict.c dict_use.c
	$(CC) $(CFLAGS) memory.c keyval.c dict.c $@.c -o $@


.PHONY : check
check : *.h *.c
	cppcheck --enable=warning --enable=style *.c

.PHONY : clean
clean :
	rm -f simple_cplx
	rm -f seamlessone
	rm -f seamlesstwo
	rm -f dict_use
	rm -rf *.dSYM
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
