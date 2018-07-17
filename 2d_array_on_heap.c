#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char** createArray(){
	char a[7][4] = {	
					1,2,3,4,
					5,6,7,8
				};

	char **ptr;
	ptr = (char **) malloc(sizeof(char *) * 7);
	for(int i=0;i<7;i++){
		ptr[i] = (char *) malloc(sizeof(char) * 4); 
		for(int j=0;j<4;j++){
			ptr[i][j] = a[i][j];
		}
	}

	return ptr;

}

void freeArray(void **arr,int x){
	for(int i=0;i<x;i++){
		free(arr[i]);
	}

	free(arr);
}

int main(){
	char **arr = createArray();

	for(int i=0;i<7;i++){
		for(int j=0;j<4;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	freeArray(arr, 7);
	return 0;
}
