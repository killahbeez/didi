CFLAGS=-Wall -g -std=gnu99 -lm 

test: test.o function.o
	gcc -Wall test.o function.o -o test

test.o: test.c function.h
	gcc -Wall -g -c test.c -o test.o

function.o: function.c
	gcc -Wall -g -c function.c -o function.o

mysql: mysql_test.c 
	gcc -Wall -g `mysql_config --cflags --libs` mysql_test.c -o mysql_test

clean:
	rm -f ./*.o ./*.s ./test

didi: test.txt
	cat $^ | head -n2 > $@.txt
