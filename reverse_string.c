#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char *reverse_str(char *str);
int main(int argc, char *argv[]){
	char *didi = "abcdefghijklmnoprstuvwxyz";
	char *rev_didi = reverse_str(didi);
	printf("Length: %d\nString: %s\nLength: %d\nReverse string: %s\n",strlen(didi),didi,strlen(rev_didi),rev_didi);
	free(rev_didi);
	return 0;
}

char *reverse_str(char *str){
	uint16_t size = strlen(str);
	char *buffer = (char *) malloc(size+1);
	int i=0;
	while(size > 0){
		*(buffer + i++) = *(str+size-1);
		size--;
	}
	*(buffer+i) = '\0';
	return buffer;
}
