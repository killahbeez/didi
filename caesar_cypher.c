#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
  char *str = "4-'3evh?'c)7%t#e-r,g6u#.9uv#%tg2v#7g'w6gA";
  uint8_t len = strlen(str);
  char *str_decode = malloc(len +1);
  memset(str_decode,0,len+1);

  for(int i=33;i<127;i++){
	  for(int j=0;j<len;j++){
		if((*(str+j)+i) > 127){
			*(str_decode+j) = 33+(*(str+j)+i)%127;
		}
		else{
			*(str_decode+j) = *(str+j)+i;
			
		}
	  }
	  if(strstr(str_decode,"pico")){
	  	printf("%d\t%s\n",i,str_decode);
	  }
  }
  free(str_decode);
  return 0;
}
