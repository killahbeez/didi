#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

int main(){
	int a = didilea();
	printf("%d :: %d\n",a,DIDI);
	char *p = strdup("muie la dezinte");
	printf("%p\n",p);
	*(p+1) = 'U';
	printf("%s\n",p);
	free(p);
	p = strdup("cacat pansat muie la dezinte");
	printf("%p\n",p);
	*(p+1) = 'U';
	printf("%s\n",p);
	free(p);
	return 0;
}
