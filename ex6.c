#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	double h = 1;
	double *ptr_h = &h;
	printf("%d\t%d\n",sizeof(ptr_h),sizeof(*ptr_h));
	char g[3][4][5] = {11,21,31,41,51,61,71,81};
	printf("%p\t%p\t%p\t%p\t%p\n",&g,g,*g,**g,&***g);
	char a[3][5] = {11,21,31,41,51,61,62,63};
	char (*p)[5] = a;
	char *ptr = *a;
	for(int i=0;i<sizeof(*a);i++){
		printf("[%d]\t%d\n",i,*(ptr+i));
	}
	printf("-------------\n");
	printf("%d\t%d\n",*(*(a+1)+2),**(p+1));
	printf("%d\t%d\t%d\n",sizeof(a),sizeof(*a),sizeof(a)/sizeof(*a));
	//test
	return 0;
}
