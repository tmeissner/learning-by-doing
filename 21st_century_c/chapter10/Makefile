CFLAGS = -Wall -O3 --std=c11


boxes : boxes.c
	$(CC) $(CFLAGS) $@.c -o $@

show_tree : process_dir.h process_dir.c show_tree.c
	$(CC) $(CFLAGS) process_dir.c $@.c -o $@


.PHONY : all
all : boxes show_tree

.PHONY : check
check : *.h *.c
	cppcheck --enable=warning --enable=style *.c

.PHONY : clean
clean :
	rm -f boxes
	rm -f show_tree
	rm -rf *.dSYM
