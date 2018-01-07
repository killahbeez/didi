#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct dog {
	char *name;
	char *breed;
	int height;
	int weight;
};

void printDog(struct dog *theDog){
	printf("Name: %s\n",theDog->name);		
	printf("Breed: %s\n",theDog->breed);		
	printf("Height: %d\n",theDog->height);		
	printf("Weight: %d\n",theDog->weight);		
}

void addressDog(struct dog *theDog){
	printf("\tAddr Name: %p\n",theDog->name);		
	printf("\tAddr Breed: %p\n",theDog->breed);		
	printf("\tAddr Height: %p\n",&theDog->height);		
	printf("\tAddr Weight: %p\n",&theDog->weight);		
}

int main(){
	char sc[50];
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	printf("From boot time: %f sec\n",start.tv_sec + ((float)start.tv_nsec / pow(10,9)));

	printf("Enter string: ");
	if(scanf("%[^\n]",sc)) printf("You entered: %s\n",sc);
	while ((getchar()) != '\n');

	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("From boot time: %f sec\n",end.tv_sec + ((float)end.tv_nsec / pow(10,9)));
	
	//testing string literal address, only once is stored if string is the same
	struct dog oscar_1 = {"oscar","labrador",30,45};
	struct dog oscar_2 = {"oscar","labrador",40,67};
	printDog(&oscar_1);
	addressDog(&oscar_1);

	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("From boot time: %f sec\n",end.tv_sec + ((float)end.tv_nsec / pow(10,9)));
	
	printDog(&oscar_2);
	addressDog(&oscar_2);

	char *didi_1 = "labrador";
	char *didi_2 = "labrador";
	printf("%p\n",didi_1);
	printf("%p\n",didi_2);

	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("From boot time: %f sec\n",end.tv_sec + ((float)end.tv_nsec / pow(10,9)));
	char buffer[200] = "didi do dexter",*str;
	str = stpcpy(buffer,"didi do dexter");
	printf("%s\n",buffer);
	for(int i=0;i<20;i++){
		*str++ = 65+i;
	}
	*str = '\0';

	printf("%s\n",buffer);
	return 0;
}
