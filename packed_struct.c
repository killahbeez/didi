#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct __attribute__((__packed__)){
		char a;
		uint32_t b;
} didi_;

typedef struct {
		char a;
		uint32_t b;
} didi1_;

int main(){
	didi_ didi = {10,1};
	printf("%d %d\n",didi.a, didi.b);
	printf("%d\n",sizeof(didi));

	if(didi.a && didi.b) printf("ok\n");
	if(!(!didi.a || !didi.b)) printf("ok\n");

	if(didi.a<4 || didi.a>9) printf("ok\n");
	if(!(didi.a>=4 && didi.a<=9)) printf("ok\n");


	char arr[] = {1,2,3,4,5,6,7,8,9,10};

	didi_ *ptr = (didi_ *)arr;
	printf("%#.8x %#.8x\n",ptr->a, ptr->b);
	printf("%#.8x %#.8x\n",(ptr+1)->a, ptr[1].b);
	return 0;
}
