CFLAGS = -Wall -O3 --std=c11


simple_cplx : cplx.h complex.c simple_cplx.c
	$(CC) `pkg-config --cflags --libs gsl` $(CFLAGS) complex.c $@.c -o $@

seamlessone : seamlessone.c
	$(CC) $(CFLAGS) -fms-extensions -Wno-microsoft $@.c -o $@

seamlesstwo : seamlesstwo.c
	$(CC) $(CFLAGS) -fms-extensions -Wno-microsoft $@.c -o $@


.PHONY : all
all : simple_cplx seamlessone seamlesstwo

.PHONY : check
check : *.h *.c
	cppcheck --enable=warning --enable=style *.c

.PHONY : clean
clean :
	rm -f simple_cplx
	rm -f seamlessone
	rm -f seamlesstwo
	rm -rf *.dSYM
