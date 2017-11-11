#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//on STACK memory locations are allocated downwards so (q-w)
	char q[] = "didi do dexter";
	char w[] = "cacat pansat ";

	uint16_t string_len = strlen(w);
	uint32_t padding_bytes = (q-w-string_len);
	// change NUL character and all the padding bytes (end of string) with a non printable one
	for(int i=0;i<padding_bytes;i++){
		*(w+string_len+i) = 1;		
	}
	printf("%s\n",w);

	//on HEAP memory locations are allocated upwards so (b-a)
	char *a = strdup("muie la dezinte ");
	char *b = strdup("marmota are mere");

	uint16_t string_len_1 = strlen(a);
	uint32_t padding_bytes_1 = (b-a-string_len_1);
	// change NUL character and all the padding bytes (end of string) with a non printable one
	for(int i=0;i<padding_bytes_1;i++){
		*(a+string_len_1+i) = 1;		
	}
	printf("%s\n",a);
}
