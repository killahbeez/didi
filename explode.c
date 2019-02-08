#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char **arr;
	uint32_t len;
} str_delim_t;

str_delim_t *explode(char *str, char *delim){
	str_delim_t *str_delim = (str_delim_t *) calloc(1,sizeof(str_delim_t));
	if(str_delim != NULL){
		uint16_t str_len = strlen(str);
		char *initial_str = (char *)malloc(str_len+1);

		if(initial_str != NULL){

			initial_str[str_len] = '\0';
			strcpy(initial_str,str);

			char *token;
			token = strtok(str, delim);

			while( token != NULL ) {
				str_delim->len++;
				str_delim->arr = (char **)realloc(str_delim->arr,str_delim->len*sizeof(char *));
				if(str_delim->arr == NULL){
					return NULL;
				}
				str_delim->arr[str_delim->len-1] = (char *) malloc(strlen(token)+1);
				strcpy(str_delim->arr[str_delim->len-1],token);
				token = strtok(NULL, delim);
			}	

			strcpy(str,initial_str);
			free(initial_str);
		}
	}

	return str_delim;
}

void free_explode(str_delim_t *str_delim){
	if(str_delim->arr != NULL && str_delim->len > 0){
		for(int i=0;i<str_delim->len;i++){
			free(str_delim->arr[i]);
		}
		free(str_delim->arr);
	}
	if(str_delim != NULL){
		free(str_delim);
	}
}

int main(int argc, char **argv){
	char str[] = "didi#gogo#gigi#mimi#leagsa##sakjsa#ewewew#sdasa";
	char *delim = "#";

	str_delim_t *str_delim = explode(str,delim);

	if(str_delim != NULL){
		for(int i=0;i<str_delim->len;i++){
			printf("%d %s\n",i,str_delim->arr[i]);
		}
		free_explode(str_delim);
	}

	printf("%s\n",str);
	return 0;
}
