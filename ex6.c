#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char a[2][3] = {
						{1,2,3},
						{4,5,6}
					};

	printf("%d\t%d\t%d\n",**a,*(*a+1),*(*a+2));
	printf("%d\t%d\n",*a,*(a+1));
	printf("%d\t%d\n",&**(a+1),**(a+1));
					
	return 0;
}
