#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char *b = (char *)malloc(6 * sizeof(char));
	printf("%p\n",b);
	strcpy(b,"hello");
	b[5] = '\0';
	b[0] = 'H';
	printf("%s\n",b);
	printf("%p\n",b);

	free(b);
	return 0;
}
