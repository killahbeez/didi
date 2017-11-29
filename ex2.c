#include <stdio.h>
#include <stdint.h>
#include <string.h>

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

int main(){
	int cnt =0;
	for(int i=0;i<3*2*3;i++){
		printf("%d\n",*((int*)didi + cnt++));
	}

	return 0;
}
