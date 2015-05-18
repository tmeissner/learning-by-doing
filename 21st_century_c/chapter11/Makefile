CFLAGS = -Wall -O0 --std=c11 -g -lm


simple_cplx : cplx.h complex.c simple_cplx.c
	$(CC) `pkg-config --cflags --libs gsl` $(CFLAGS) complex.c $@.c -o $@

seamlessone : seamlessone.c
	$(CC) $(CFLAGS) -fms-extensions -Wno-microsoft $@.c -o $@

seamlesstwo : seamlesstwo.c
	$(CC) $(CFLAGS) -fms-extensions -Wno-microsoft $@.c -o $@

dict_use : keyval.h keyval.c dict.h dict.c dict_use.c
	$(CC) $(CFLAGS) keyval.c dict.c $@.c -o $@


.PHONY : all
all : simple_cplx seamlessone seamlesstwo dict_use

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
