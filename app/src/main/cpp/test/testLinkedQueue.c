//
// Created by Nick Lai on 2021/10/3.
//

#include <stdio.h>
#include "../storeutils/LinkedQueue.h"

int main() {
    LinkedQueue queue = InitQueue();
    char *str = "A string for testing LinkedQueue.";

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
    return 0;
}