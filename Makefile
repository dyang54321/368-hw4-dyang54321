WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DOPEN -DCLOSE -DLIST_PRINT -DSWITCH
SRCS = main.c a4.c
OBJS = $(SRCS:%.c=%.o)

a4: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o a4

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: a4
	$(VAL) ./a4

testall: test1 test2 test3 test4 test5

test1: a4
	./a4 "open 0"

clean:
	rm -f a4 *.o *.txt output? *~