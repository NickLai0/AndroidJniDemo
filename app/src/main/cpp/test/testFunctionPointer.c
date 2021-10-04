//
// Created by Nick Lai on 2021/10/4.
//
#include<stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void test1() {
    int (*maxFun)(int, int) = &max;
    int a = 100, b = 200;
    int max = (*maxFun)(a, b);
    printf("test1-> (%d,%d)max=%d", a, b, max);
}

void test2(int (*maxFun)(int, int)) {
    int a = 400, b = 200;
    int max = (*maxFun)(a, b);
    printf("test2-> (%d,%d)max=%d", a, b, max);
}

int main() {
//   test1();
    test2(&max);
}