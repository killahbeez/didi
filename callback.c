#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef int32_t (*calc)(int32_t a,int32_t b);

int32_t add(int32_t a,int32_t b){
	return (a+b);
}

int32_t diff(int32_t a,int32_t b){
	return (a-b);
}

int32_t multiply(int32_t a,int32_t b){
	return (a*b);
}

int32_t subtract(int32_t a,int32_t b){
	return (a/b);
}

int32_t operation(calc callback,int32_t a,int32_t b){
	return callback(a,b);
}

typedef struct {
	char *description;
	calc op;
} operands;

operands ops[] = {
					{
						"Add %d + %d = %d\n",
						add
					},
					{
						"Diff %d - %d = %d\n",
						diff
					},
					{
						"Multiply %d * %d = %d\n",
						multiply
					},
					{
						"Subtract %d / %d = %d\n",
						subtract
					}
				};
int main(){
	for(uint8_t i=0;i<sizeof(ops)/sizeof(*ops);i++){
		printf(ops[i].description,40,20,operation(ops[i].op,40,20));
	}
	return 0;
}
