#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void fileASCII(){
	int a = 123;
	FILE *fp;
	fp = fopen("test.txt","w+");

	if(fp == NULL){
		printf("Error creating file\n");
		exit(1);
	}
	printf("Creating ascii file test.txt\n");
	char buffer[100];
	sprintf(buffer,"%d",a);
	if(fputs(buffer,fp) == EOF){
		printf("Error writing\n");
		exit(1);
	}
	printf("Writing buffer: %s\n",buffer);
	fclose(fp);
}

void fileBIN(){
	uint16_t a[] = {123,45,234,0b1000000001,0x1122};
	FILE *fp;
	fp = fopen("testBIN.txt","w+");

	if(fp == NULL){
		printf("Error creating file\n");
		exit(1);
	}
	printf("Creating ascii file testBIN.txt\n");
	if(fwrite(&a,sizeof(*a), sizeof(a)/sizeof(*a), fp) != sizeof(a)/sizeof(*a)){
		printf("Error writing\n");
		exit(1);
	}
	printf("Writing to testBIN\n");
	uint16_t tmp[3];
	fseek(fp,2*sizeof(*tmp),SEEK_SET);
	fread(tmp,sizeof(*tmp),3,fp);
	for(int i=0;i<sizeof(tmp)/sizeof(*tmp);i++){
		printf("\t%d\n",tmp[i]);
	}
	fclose(fp);
}

int main(){
	fileASCII();
	fileBIN();
	return 0;
}
