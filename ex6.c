#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

uint8_t *digits_1(uint64_t nr, uint8_t *count){
	uint8_t *dig = malloc(1*sizeof(uint8_t));
	assert(dig != NULL);
	uint8_t cur = 0;
	while(nr / 10 > 0){
		(*count)++;
		cur = nr%10;
		nr /= 10;
		*(dig+*count-1) = cur;
		dig = realloc(dig,(*count+1) * sizeof(uint8_t));
		assert(dig != NULL);
	}
	*(dig+*count) = nr;

	return dig;
}

void digits_2(uint64_t nr, uint8_t **buffer, uint8_t *count){
	*buffer = (uint8_t *)malloc(1*sizeof(uint8_t));
	assert(*buffer != NULL);
	uint8_t cur = 0;
	while(nr / 10 > 0){
		(*count)++;
		cur = nr%10;
		nr /= 10;
		*(*buffer+*count-1) = cur;
		*buffer = (uint8_t *) realloc(*buffer,(*count+1) * sizeof(uint8_t));
		assert(*buffer != NULL);
	}
	*(*buffer+*count) = nr;
}

int main(){
	printf("Method 1:\n");
	uint64_t nr = 1234434324256789;
	uint8_t cnt_digits = 0;
	uint8_t *result = digits_1(nr,&cnt_digits);
	printf("Number: %llu\n",(long long)nr);
	printf("Total digits: %d\n",cnt_digits+1);
	for(int i=0;i<=cnt_digits;i++){
		printf("%d\t%d\n",i+1,*(result+i));
	}
	free(result);

	printf("\n------------------------\n");
	printf("\nMethod 2:\n");
	uint8_t *result_1 = NULL;
	uint8_t cnt_digits_1 = 0;
	digits_2(nr,&result_1,&cnt_digits_1);
	printf("Number: %llu\n",(long long)nr);
	printf("Total digits: %d\n",cnt_digits_1+1);
	for(int i=0;i<=cnt_digits_1;i++){
		printf("%d\t%d\n",i+1,*(result_1+i));
	}
	free(result_1);
	return 0;
}
