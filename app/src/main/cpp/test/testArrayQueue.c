//
// Created by Nick Lai on 2021/10/3.
//

#include <stdio.h>
#include "../storeutils/ArrayQueue.h"

void test1();

void test2();

int main() {
//    test1();
    test2();
    return 0;
}

void test2() {
    int const N = 8;
    ArrayQueue queue = InitQueue(N);
    char *str = "A string for testing ArrayQueue.";
    int index = 0;
    //Input n-1 elements.
    for (int i = 1; i < N; ++i) {
        Enqueue(queue, &str[index++]);
    }
    char *ch;
    //Output n-1 elements.
    while (Size(queue) > 0) {
        ch = Poll(queue);
        putchar(*ch);
    }
    printf("\n");
    //Input n+1 elements.
    for (int i = 1; i <= N + 1; ++i) {
        Enqueue(queue, &str[index++]);
    }
    //Output n+1 elements and see whether it works normal.
    while (Size(queue) > 0) {
        ch = Poll(queue);
        putchar(*ch);
    }
    UninitQueue(queue);
}

void test1() {
    ArrayQueue queue = InitQueue(8);
    char *str = "A string for testing ArrayQueue.";

    printf("IsEmptyQueue=%d, size=%d\n",
           IsEmptyQueue(queue), Size(queue));
    printf("Enqueue the string: %s\n", str);
    for (int i = 0; str[i] != '\0'; i++) {
        Enqueue(queue, &str[i]);
    }
    printf("IsEmptyQueue=%d, size=%d\n",
           IsEmptyQueue(queue), Size(queue));

    printf("The first character is %c\n",
           *((char *) GetHead(queue)));

    printf("Dequeue the string: ");
    char *ch;
    while ((ch = Poll(queue)) != NULL) {
        putchar(*ch);
    }
    printf("\n");

    printf("IsEmptyQueue=%d, size=%d\n",
           IsEmptyQueue(queue), Size(queue));

    UninitQueue(queue);
}
