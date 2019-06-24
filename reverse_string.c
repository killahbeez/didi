#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char *reverse_str(char *str);
char *reverse_str_XOR(char *str);

int main(int argc, char *argv[]){
	char *didi = "abcdefghijklmnoprstuvwxyz";
	char *rev_didi = reverse_str(didi);
	char *didi_1 = "abcdefghijklmnoprstuvwxyz";
	char *rev_didi_1 = reverse_str_XOR(didi_1);
	printf("Length: %d\nString: %s\nLength: %d\nReverse string: %s\n",strlen(didi),didi,strlen(rev_didi),rev_didi);
	printf("Length: %d\nString: %s\nLength: %d\nReverse string: %s\n",strlen(didi_1),didi_1,strlen(rev_didi_1),rev_didi_1);
	free(rev_didi);
	free(rev_didi_1);
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

char *reverse_str_XOR(char *str){
	uint16_t size = strlen(str);
	char *buffer = (char *) malloc(size+1);
	memcpy(buffer,str,size+1);
	int i=0;
	while(i<size/2){
		*(buffer+i) ^= *(buffer+size-1-i);
		*(buffer+size-1-i) ^= *(buffer+i);
		*(buffer+i) ^= *(buffer+size-1-i);
		i++;
	}
	return buffer;
}
