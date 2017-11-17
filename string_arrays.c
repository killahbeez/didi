#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
	char *strings[] = {"didi","dexter","cacat", "pansat","gargamel"};
	//Advantages:
	//	you can reassign the string like strings[0] = "gigi"
	//Disadvantages
	//	assign string literals (constant) so you can't do strings[0][0] = 'G'; 

	printf("Array dimension: %d\n",sizeof(strings)/sizeof(strings[0]));
	for(int i=0;i<sizeof(strings)/sizeof(strings[0]);i++){
		//*(strings[i]+1) = 'G'; can't change string literals
		//strings[i] = "didi"; can reassign to point to another string literal
		printf("%s\n",strings[i]);
	}

	char str_arr[][100] = {"didi","dexter","cacat", "pansat","gargamel"};
	//Advantages:
	//	you can change the string like str_arr[0][0] = 'C'
	//Disadvantages
	//  you can't directly assign str_arr[0] = "didi", just use strcpy 

	uint8_t dim_arr = 5;
	printf("Array dimension: %d\n",dim_arr);
	for(int i=0;i<dim_arr;i++){
		//str_arr[i] = "didi"; //can't reassign to point to another string literal
		str_arr[i][0] = 'G'; 
		printf("%s\n",str_arr[i]);
	}
	return 0;
}
