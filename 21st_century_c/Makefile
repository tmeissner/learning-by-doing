CFLAGS = --std=c11 -Wall -O3


boxes : boxes.c
	$(CC) $(CFLAGS) $@.c -o $@

show_tree : process_dir.h process_dir.c show_tree.c
	$(CC) $(CFLAGS) process_dir.c $@.c -o $@

simple_cplx : cplx.h complex.c simple_cplx.c
	$(CC) `pkg-config --cflags --libs gsl` $(CFLAGS) complex.c $@.c -o $@

.PHONY : all
all : boxes show_tree simple_cplx

.PHONY : clean
clean :
	rm -f boxes
	rm -f show_tree
	rm -f simple_cplx
