#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
	int c;
} didi_t;

didi_t chg(){
	didi_t didi = {10,20,30};

	return didi;
}
int main(){
	didi_t g = chg();
	printf("%d %d %d\n",g.a,g.b,g.c);
	return 0;
}
