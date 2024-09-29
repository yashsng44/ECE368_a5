WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror 
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --show-leak-kinds=all --verbose

SRCS = main.c a5.c
OBJS = $(SRCS:%.c=%.o)

a5: $(OBJS)
	$(GCC) $(OBJS) -o a5 -lm

.c.o:
	$(GCC) -c $*.c

test_file: a5
	$(VAL) ./a5 test.txt 

clean: # remove all machine generated files
	rm -f a5 *.o output? *~ 

