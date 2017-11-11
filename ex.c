#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* didi();

int main(){
	char q[] = "didi do dexter";
	char w[] = "cacat pansat ";

	uint16_t string_len = strlen(w);
	uint32_t padding_bytes = (q-w-string_len);
	// change NUL character and all the padding bytes (end of string) with a non printable one
	for(int i=0;i<padding_bytes;i++){
		*(w+string_len+i) = 1;		
	}
	printf("%s\n",w);

	char* didilea = NULL;
	didilea = (char *) didi();
	*(didilea + 1) = 'U';
	printf("%p\t%p\t %s\n",didilea,&didilea,didilea);
	free(didilea);
	return 0;
}

char* didi(){
	char *a = strdup("muie la dezinte");
	return a;
}
