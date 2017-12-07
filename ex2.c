#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int didi[][2][3] = {
		{
			{1,2,3},
			{4,5,6}
		},
		{
			{7,8,9},
			{10,11,12}
		},
		{
			{13,14,15},
			{16,17,18}
		}
};

void swap(int *,int *);

int main(){
	int cnt =0;
	for(int i=0;i<3*2*3;i++){
		printf("%d\n",*((int*)didi + cnt++));
	}

	int a = -345;
	int b = 786;
	printf("a: %d\tb: %d\n", a, b);
	swap(&a,&b);
	printf("a: %d\tb: %d\n", a, b);
	struct timespec tim;
   	tim.tv_sec = 0;
    tim.tv_nsec = 500000000;

	for(int i=0;i<10;i++){
		nanosleep(&tim, NULL);
		printf("\t%d\n",i);
	}
	return 0;
}

void swap(int *a,int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
