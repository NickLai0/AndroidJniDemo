/*
 * removeRepeatedCharacters.cpp
 *
 *  Created on: 2021Äê6ÔÂ26ÈÕ
 *      Author: Nick Lai
 */

#include <stdio.h>
#include <cstring>
int main(){
	
	int i,j,k,len;
	char str[80],ch,temp;
	for(len=0; (ch=getchar()) != '#'; len++) {
		str[len]=ch;
		printf("%c",str[len]);
	}
	printf("\n");
	
	if(len == 0){
			printf("There is no string.");
	} else {
			//Removing repeated characters.
			for(i = 0; i< len; i++) {
				for(j=i+1; j<len; j++) {
					if(str[i] == str[j]) {
						//printf("%c == %c, i=%d, j=%d\n",str[i],str[j],i,j);
						for(k=j; k<len; k++) {
							str[k] = str[k+1]; 
						}
						i--;
						len--;
						break;
					}	
				}
			}
			//Todo:xxx Bubble sort for str from smaller to larger.
			for(i = 0; i < len - 1; i++) {
				for(j = 0; j < len  - 1- i;j++ ){
					if(str[j] > str[j+1]) {
						temp = str[j];
						str[j] = str[j+1];
						str[j+1] + temp;
					}
				}
			}
			//Print all of characters.
			printf("len=%d\n", len);
			for(i = 0; i < len; i++) {
				printf("%c", str[i]);
			}
		}
	
	return 0;
}


