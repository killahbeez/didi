#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	uint8_t *a = malloc(1);
	uint32_t *b = malloc(4);
	
	uint8_t size_info_header = 4; // number of bytes for header heap chunk
	uint32_t *heap_size = (uint32_t *)(a-size_info_header);
	uint32_t heap_bytes_alloc =	( *heap_size >> 3 << 3 ) - size_info_header; // the last three bytes are for other purpose so set to 000
	printf("HEAP Memory size allocated: %d bytes\n",heap_bytes_alloc);

	for(uint32_t i=0;i<heap_bytes_alloc;i++){
		*(a+i) = i;
	}
	for(uint32_t i=0;i<heap_bytes_alloc;i++){
		printf("%d\t%d\n",i,*(a+i));
	}
	*b=0x11223344;
	printf("b: %u\n",*b);
	free(b);
	free(a);
	return 0;
}
