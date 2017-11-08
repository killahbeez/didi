#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main(){
	uint8_t a1 = 23;
	uint8_t a2 = 32;
	printf("%d\n",&a1);
	printf("%d\n",&a2);
	uint8_t *ptr_1 = &a2;
	printf("   %d\n",ptr_1);
	printf("%d\n",*ptr_1++);
	printf("   %d\n",ptr_1);
	printf("%d\n",*ptr_1);
	return 0;
}
