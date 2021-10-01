//
// Created by Nick Lai on 2021/7/6.
//

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("test/test.text", "w");
    int fputcRetrieve = fputc('a', fp);
    printf("fputcRetrieve=%d\n", fputcRetrieve);
    int closeRetrieve = fclose(fp);
    printf("closeRetrieve=%d", closeRetrieve);
    return 0;
}