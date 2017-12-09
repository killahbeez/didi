#include <stdio.h>
#include <stdint.h>

static union test {
	uint32_t whole;
	struct {
		char c0;
		char c1;
		char c2;
		char c3;
	} bytes;
} int2byte;

int main(int argc, char *argv[]){
	int2byte.whole = 0x11223344;
	printf("sizeof union: %d bytes\n",sizeof(int2byte));
	printf("int2byte address: %p\n",&int2byte);
	printf("c0 address: %p\n",&(int2byte.bytes.c0));
	printf("c1 address: %p\n",&(int2byte.bytes.c1));
	printf("c2 address: %p\n",&(int2byte.bytes.c2));
	printf("c3 address: %p\n",&(int2byte.bytes.c3));
	printf("%x\n",int2byte.whole);
	printf("c0: %x\tc1: %x\tc2: %x\tc2: %x\n",
			int2byte.bytes.c0,
			int2byte.bytes.c1,
			int2byte.bytes.c2,
			int2byte.bytes.c3);
	return 0;
}
