#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

struct __attribute__((__packed__)){
		char a;
		uint32_t b;
} didi = {1,1};

int main(){
	
	printf("%d %d\n",didi.a, didi.b);
	printf("%d\n",sizeof(didi));

	if(didi.a && didi.b) printf("ok\n");
	if(!(!didi.a || !didi.b)) printf("ok\n");
	return 0;
}
