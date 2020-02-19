#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *didi(){
	static int b =67;
	int *a=&b;
	return a;
}

int main() {
	int *c=didi();
	printf("%d\n",*c);
}	
