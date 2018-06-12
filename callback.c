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

calc ops[] = {
					add,
					diff,
					multiply,
					subtract
};

char *descr[] = {
	"Add %d + %d =\t%d\n",
	"Diff %d - %d =\t%d\n",
	"Multiply %d * %d =\t%d\n",
	"Subtract %d / %d =\t%d\n"
};

int main(){
	for(uint8_t i=0;i<sizeof(ops)/sizeof(*ops);i++){
		printf(descr[i],40,20,operation(ops[i],40,20));
	}
	return 0;
}
