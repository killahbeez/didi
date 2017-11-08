#include <stdio.h>
#include <stdint.h>

union test {
	uint32_t a;
	struct {
		char c0;
		char c1;
		char c2;
		char c3;
	} bytes;
};

int main(int argc, char *argv[]){
	union test int2byte;
	int2byte.a = 0x11223344;
	printf("%x\n",int2byte.a);
	printf("c0: %x\tc1: %x\tc2: %x\tc2: %x\n",
			int2byte.bytes.c0,
			int2byte.bytes.c1,
			int2byte.bytes.c2,
			int2byte.bytes.c3);
	return 0;
}
