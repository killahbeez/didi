#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int** createArray(){
	int a[7][4] = {	
					1,2,3,4,
					5,6,7,8
				};

	int **ptr;
	ptr = (int **) malloc(sizeof(int *) * 7);
	for(int i=0;i<7;i++){
		ptr[i] = (int *) malloc(sizeof(int) * 4); 
		for(int j=0;j<4;j++){
			ptr[i][j] = a[i][j];
		}
	}

	return ptr;

}
int main(){
	int **arr = createArray();

	for(int i=0;i<7;i++){
		for(int j=0;j<4;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
