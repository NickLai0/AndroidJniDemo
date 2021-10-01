//
// Created by Nick Lai on 2021/10/1.
//

#include <stdio.h>
#include <malloc.h>
#include <stddef.h>

void testPointer1();

void testPointer2();

int main() {
//    testPointer1();
    testPointer2();
    return 0;
}

void testPointer2() {
    void **pointers = (void **) malloc(10 * sizeof(void *));
    int num = 65;
    char ch = 'A';
    double  doubl= 3.141592653;
    void *voi = &doubl;
    pointers[0] = &num;
    pointers[1] = (void *) &ch;
    pointers[2] = (void *) &doubl;
    pointers[3] = (void *) voi;
}

void testPointer1() {
    int **pointers = (int **) malloc(10 * sizeof(int *));
    int num = 65;
    char ch = 'A';
    long long lon = 200;
    void *voi = &lon;
    pointers[0] = &num;
    pointers[1] = (int *) &ch;
    pointers[2] = (int *) &lon;
    pointers[3] = (int *) voi;
    printf("%d=%c, lon=%ld, voi=%ld", *pointers[0], *pointers[1], *pointers[2], *pointers[3]);
}
