#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
	int *a1 = malloc(4*sizeof(int));
	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;
	int *a2 = NULL;
	a2 = a1;
	a2[1] = 666;
	for(int i=0;i<4;i++){
		printf("%d\n",a1[i]);
	}
	free(a1);

	uint16_t b1[] = {1,2,3,4};
	uint16_t b2[4];

	printf("sizeof: %d\n",sizeof(b1));
	memcpy(b2,b1,sizeof(b1));
	b2[1] = 666;
	for(int i=0;i<sizeof(b1)/sizeof(b1[0]);i++){
		printf("%d\n",b1[i]);
	}
	for(int i=0;i<sizeof(b2)/sizeof(b2[0]);i++){
		printf("%d\n",b2[i]);
	}
	return 0;
}
