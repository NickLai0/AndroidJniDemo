//
// Created by Nick Lai on 2021/10/2.
//

#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include "LinkedStack.h"

LinkedStack InitStack() {
    LinkedStack stack = malloc(sizeof(LinkedStackStructure));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void UninitStack(LinkedStack stack) {
    if (stack != NULL) {
        while (stack->size > 0) { Pop(stack); }
        free(stack);
    }
}

int Size(LinkedStack stack) {
    if (stack == NULL) {
        return -1;
    }
    return stack->size;
}

int Length(LinkedStack stack) {
    if (stack == NULL) {
        return -1;
    }
    return INT32_MAX;
}

int IsEmptyStack(LinkedStack stack) {
    if (stack == NULL) { return 1; }
    return stack->size == 0;
}

void *Push(LinkedStack stack, void *element) {
    if (stack == NULL) { return NULL; }
    LinkedStackNodeStructure *node = malloc(sizeof(LinkedStackNodeStructure));
    node->element = element;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return element;
}

void *Pop(LinkedStack stack) {
    void *element = NULL;
    if (stack != NULL && stack->size > 0) {
        LinkedStackNodeStructure *node = stack->top;
        stack->top = stack->top->next;
        stack->size--;

        element = node->element;
        free(node);
    }
    return element;
}

void *GetTop(LinkedStack stack) {
    if (stack != NULL && stack->size > 0) {
        return stack->top->element;
    }
    return NULL;
}