#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void change_string(char *str_dest, char *str_src, uint8_t size);
char *change_string_literal(char *str);

int main(){
	char didi[] = "mui";
	char dexter[] = "did";
	printf("%s\n",dexter);
	dexter[3]=32;//change NUL to SPACE
	printf("%s\n",dexter);
	/*char didi[] = "didilea";
	printf("Before: %s\n",didi);	
	change_string(didi,"marmota",strlen(didi));
	printf("After: %s\n",didi);	

	char *dexter = "dexter";
	printf("Before: %s\n",dexter);	
	dexter = change_string_literal(dexter);
	printf("After: %s\n",dexter);*/

	uint32_t a[8] = {16,26,36,46,56,66,76,86};
	uint32_t i = 1;
	a[8] = 123;
	struct timespec tm = {0,100000000L};
	for(i=0;i<11;i++){
		a[i] = 2;
		printf("%d\t%d\n",i,a[i]);
		nanosleep(&tm,NULL);
	}	
	return 0;
	
}

void change_string(char *str_dest, char *str_src, uint8_t size){
	strncpy(str_dest,str_src,size);
	*(str_dest+size) = '\0';
}

char *change_string_literal(char *str){
	str = "muie la dezinte";
	return str;
}
