//
// Created by Nick Lai on 2021/10/2.
//

#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "ArrayStack.h"

ArrayStack InitStack(int size) {
    ArrayStack stack = malloc(sizeof(ArrayStackStructure));
    if (size < 8) {
        size = 8;
    }
    stack->data = malloc(size * sizeof(void *));
    stack->top = 0;
    stack->length = size;
    return stack;
}

void UninitStack(ArrayStack stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}

int Size(ArrayStack stack) {
    return stack->top;
}

int Length(ArrayStack stack) {
    return stack->length;
}

int IsEmptyStack(ArrayStack stack) {
    return stack->top == 0;
}

void Push(ArrayStack stack, void *element) {
    if (stack->top == stack->length) {
        int newLength = stack->length + stack->length / 2;
        void **newData = malloc(newLength * sizeof(void *));
        memcpy(newData, stack->data, stack->length * sizeof(void *));
        free(stack->data);
        stack->data = newData;
        stack->length = newLength;
    }
    stack->data[stack->top] = element;
    stack->top++;
}

void *Pop(ArrayStack stack) {
    if (stack->top > 0) {
        --stack->top;
        return stack->data[stack->top];
    }
    return NULL;
}

void *GetTop(ArrayStack stack) {
    if (stack->top > 0) {
        return stack->data[stack->top - 1];
    }
    return NULL;
}
