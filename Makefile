CFLAGS = -Wall -g -std=gnu99 -lm 
OBJECTS = ex ex1 ex2 ex3 ex4 ex6 didilea file heap_size_overflow int2byte mysql_test reverse_string string_arrays test didi.txt

test: test.o function.o
	gcc -Wall $^ -o $@

test.o: test.c function.h
	gcc -Wall -g -c test.c -o $@

function.o: function.c
	gcc -Wall -g -c $^ -o $@

mysql: mysql_test.c 
	gcc -Wall -g `mysql_config --cflags --libs` mysql_test.c -o mysql_test

clean:
	rm -f ./*.o ./*.s ./test
	rm -f ${OBJECTS}

didi: test.txt
	cat $^ | head -n2 > $@.txt
