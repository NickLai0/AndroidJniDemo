#include <stdio.h>
#include <string.h>

void concat(char *str1,char *str2,char *result) {
    while(*str1 != '\0') {
        *result = *str1;
        str1++;
        result++;
    }
    
    while(*str2 != '\0') {
        *result = *str2;
        str2++;
        result++;
    }
    
    *result = '\0';
}

int main(void) { 
    char str1[40], str2[40], result[80];
    printf("Enter string A: ");
    gets(str1);
    printf("Enter string B: ");
    gets(str2);
    concat(str1, str2, result);
    printf("Result: %s", result);
	return 0;
}