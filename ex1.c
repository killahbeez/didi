#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


int main(){
	typedef struct {
		uint8_t c0, c1, c2, c3;
	} byte_t;

	typedef struct {
		uint16_t c0, c1;
	} two_bytes_t;

	union {
		uint32_t whole;
		byte_t byte;
		two_bytes_t two_bytes;
	} didi;

	didi.whole = 16908287;
	printf("%d\n%d %d %d %d\n%d %d\n",didi.whole,didi.byte.c0,didi.byte.c1,didi.byte.c2,didi.byte.c3,didi.two_bytes.c0,didi.two_bytes.c1);

	uint8_t a[] = {10,20,3,4};
	uint8_t *b;
	uint8_t c[4] = {5,6,7,8};
	b = a;
	for(int i=0;i<4;i++){
		printf("%d\t%d\n",i,b[i]);
	}
	b = c;
	for(int i=0;i<4;i++){
		printf("%d\t%d\n",i,b[i]);
	}
	return 0;
}
