#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char first[] = "1234567";
	char middle[] = "1234567";
	char last[] = "1234567";

	middle[-2] = 'X';
	printf("first: %s\n",first);
	printf("middle: %s\n",middle);
	printf("X last: %s\n",last);
/*	const char *str[] = {"didi","dodoleamarmota","dexter","muie"};
	for(int i=0;i<sizeof(str)/sizeof(*str);i++){
		printf("\t%d\n",*(str+i));
		char *pt = *(str+i);
		while(*pt)
			printf("%c\n",*pt++);
	}
	uint32_t a = 0x11223344;
	uint8_t *b = (uint8_t *) &a;
	printf("%x %x\n",*b,*b+2);
	char b[]={4,51,61,13};
	printf("%d\t%d\n",*b+1,*((&b+1)-1));
	char a[10][3] = {
						{11,21,3},
						{4,5,6}
					};

	printf("%d\n",*(*a+1));
	printf("%d\n",**a);
	printf("%d\t%d\t%d\n",**a,*(*a+1),*(*a+2));
	printf("%d\t%d\n",*a,*(a+1));
	printf("%d\t%d\n",&**(a+1),&*(*(a+1)+1));
	printf("%d\n",*(*a+5));
					
	printf("%d\t%d\t%d\n",a,a+1,&a+1);
*/
	return 0;
}
