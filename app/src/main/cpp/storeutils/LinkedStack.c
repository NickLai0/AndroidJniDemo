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

int Size(LinkedStack stack) { return stack->size; }

int Length(LinkedStack stack) {
    return INT32_MAX;
}

int IsEmptyStack(LinkedStack stack) {
    return stack->size == 0;
}

void Push(LinkedStack stack, void *element) {
    LinkedStackNode *node = malloc(sizeof(LinkedStackNode));
    node->element = element;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void *Pop(LinkedStack stack) {
    void *element = NULL;
    if (stack->size > 0) {
        LinkedStackNode *node = stack->top;
        stack->top = stack->top->next;
        stack->size--;

        element = node->element;
        free(node);
    }
    return element;
}

void *GetTop(LinkedStack stack) {
    if (stack->size > 0) {
        return stack->top->element;
    }
    return NULL;
}