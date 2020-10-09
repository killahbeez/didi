#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *didi(){
	static int b =67;
	return &b;
}

int main() {
	int *c=didi();
	printf("%d\n",*c);
}	
