#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t a = 0;

int main(){
	uint8_t *ptr = (uint8_t *) malloc(2);
	uint32_t b = 23;
	*ptr = 5;
	*(ptr+1) = 6;

	for(int i=0;i<2;i++){
		printf("%p\t%d\n",&(ptr[i]),ptr[i]);
	}

	free(ptr);
	return 0;
}
