//
// Created by Nick Lai on 2021/7/6.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char ch, fileName[64];

    printf("Input a text file path: ");
    scanf("%s", fileName);

    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Can not open file: %s", fileName);
        exit(1);
    }
    while (!feof(fp)) {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    fclose(fp);

    return 0;
}