#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

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
	printf("Enter string: ");
	scanf("%[^\n]",sc);
	printf("You entered: %s\n",sc);
	struct dog oscar_1 = {"oscar","labrador",30,45};
	struct dog oscar_2 = {"oscar","labrador",40,67};
	printDog(&oscar_1);
	addressDog(&oscar_1);
	printDog(&oscar_2);
	addressDog(&oscar_2);
	char *didi_1 = "labrador";
	char *didi_2 = "labrador";
	printf("%p\n",didi_1);
	printf("%p\n",didi_2);
	return 0;
}
