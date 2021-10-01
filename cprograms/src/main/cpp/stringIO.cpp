/*
 * stringInput.cpp
 *
 *  Created on: 2021Äê6ÔÂ25ÈÕ
 *      Author: Nick Lai
 */


#include <stdio.h>
#include <string.h>

int main(){
		char str[2][5];
		printf("Before inpout:\n");
		printf("str[0]=%d, str[1]=%d\n",str[0],str[1]);
		printf("size of str[0]=%d, str[1]=%d\n",sizeof(str[0]),sizeof(str[1]));
		printf("length of str[0]=%d, str[1]=%d\n",strlen(str[0]),strlen(str[1]));
		gets(str[0]);
		scanf("%s",str[1]);
		printf("----------------------------------------------------------\n");
		printf("After inpout:\n");
		printf("str[0]=%d, str[1]=%d\n",str[0],str[1]);
		printf("size of str[0]=%d, str[1]=%d\n",sizeof(str[0]),sizeof(str[1]));
		printf("length of str[0]=%d, str[1]=%d\n",strlen(str[0]),strlen(str[1]));
		puts(str[0]);
		printf("%s",str[1]);
		return 0;
}

