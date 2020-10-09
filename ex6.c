#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void didi(){
	static char a=0;
	a++;
	didi();
}
int main(){
	didi();
	return 0;
}
