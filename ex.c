#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* didi();

int main(){
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
