#include <stdio.h>
#include <cstring>
int main(void){
	char str1[]="Hello!";
	char str2[]="World!";
	printf("%d", strcmp(str1,str2));
	return 0;
}