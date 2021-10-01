#include <stdio.h>
#include <math.h>
#include <limits.h>
#define MAX_CHAR  81

int main(void){
	int i, count=0;
	char str[MAX_CHAR]={0};
	for(i = 0; i <MAX_CHAR-1; i++){
		str[i] = getchar();
		if(str[i] == '\n'){
			break;
		}
		count++;
	}
	printf("\n");
	i=0;
	while(str[i]!=0 && str[i]!='\n' ){
		printf("%c",str[i]);
		i++;
	}
	printf("\n");
	printf("The count of the string is %d",count);
	return 0;
}




