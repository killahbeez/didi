CFLAGS = -Wall -g -std=gnu99 -lm

SOURCES := $(shell ls *.c)
OBJECTS := $(subst .c,.o,$(SOURCES))
EXECS := $(shell find . -maxdepth 1 -type f -executable)

test: test.o function.o
	gcc $(CFLAGS) $^ -o $@

test.o: test.c function.h
	gcc $(CFLAGS) -c test.c -o $@

function.o: function.c
	gcc $(CFLAGS) -c $^ -o $@

%: %.c
	gcc $(CFLAGS) $^ -o $@

.PHONY: clean didi

mysql_test: mysql_test.c 
	gcc $(CFLAGS) `mysql_config --cflags --libs` mysql_test.c -o mysql_test

clean:
	rm -f ./test ./didi.txt
	rm -f $(EXECS) $(OBJECTS)

didi: test.txt
	cat $^ | head -n2 > $@.txt

