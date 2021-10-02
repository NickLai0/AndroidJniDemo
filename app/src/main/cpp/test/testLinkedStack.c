//
// Created by Nick Lai on 2021/10/2.
//

#include <stdio.h>
#include "../storeutils/LinkedStack.h"

int main() {
    int const INIT_SIZE = 8;
    LinkedStack stack = InitStack();
    char *str = "Hello World!!!";
    char *ch = NULL;
    printf("Before pushing data: IsStackEmpty=%d\n", IsStackEmpty(stack));
    printf("Pushing string of \"%s\"\n", str);
    for (int i = 0; str[i] != '\0'; ++i) {
        Push(stack, &str[i]);
    }
    printf("After pushing data: IsStackEmpty=%d, size=%d, length=%d\n",
           IsStackEmpty(stack), Size(stack), Length(stack));

    ch = GetTop(stack);
    printf("\nGetTop(stack)=%c\n", *ch);

    printf("\n\nPopping all of data: \n");
    while (!IsStackEmpty(stack)) {
        ch = Pop(stack);
        printf("%c", *ch);
    }
    printf("\n");
    printf("size=%d, length=%d\n", Size(stack), Length(stack));

    UninitStack(stack);
    return 0;
}