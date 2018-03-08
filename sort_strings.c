/* Test case by Paul Eggert <eggert@twinsun.com> */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

struct big { 
				char *c;
				uint32_t cnt;
};
struct big *array;

int compare (void const *a1, void const *b1)
{
	struct big const *a = a1;
	struct big const *b = b1;

	return strcmp(a->c, b->c);
}

int main (int argc, char **argv)
{
	char *didi[] = {
		"there",
		"are",
		"two",
		"main",
		"types",
		"of",
		"memory",
		"you",
		"seem",
		"to",
		"be",
		"confusing"
	};
	size_t array_members = sizeof(didi)/sizeof(*didi);
	array = (struct big *) malloc (array_members * sizeof (struct big));
	printf("Number of strings: %d\n",array_members);
	if (array == NULL)
	{
		printf("Can't allocate memory for struct array");
		exit(0);
	}
	printf("Initial strings:\n");
	for (size_t i = 0; i < array_members; i++){
		array[i].c = strdup(didi[i]);
		array[i].cnt = i;
		if (array[i].c == NULL)
		{
			printf("Can't allocate memory for string: %d\t%s",i,didi[i]);
			exit(0);
		}
		printf("\t%d:\t%s\n",array[i].cnt,array[i].c);
	}

	printf("________________\n");
	printf("After sorting strings:\n");
	qsort (array, array_members, sizeof *array, compare);

	for(size_t i = 0;i<array_members;i++){
		printf("\t%d:\t%s\n",array[i].cnt,array[i].c);
		free(array[i].c);
	}
	free(array);
	return 0;
}

