CFLAGS=-Wall -g -std=gnu99 -lm 

test: test.o function.o
	gcc -Wall test.o function.o -o test

test.o: test.c function.h
	gcc -Wall -g -c test.c -o test.o

function.o: function.c
	gcc -Wall -g -c function.c -o function.o

clean:
	rm -f *.o *.s test

didi: test.txt
	cat $^ | head -n2 > $@.txt
