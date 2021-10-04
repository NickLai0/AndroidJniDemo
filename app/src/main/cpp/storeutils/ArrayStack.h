//
// Created by Nick Lai on 2021/10/2.
//

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct {
    void **data;
    int length;
    int top;
} ArrayStackStructure, *ArrayStack;

ArrayStack InitStack(int size);

void UninitStack(ArrayStack stack);

int Size(ArrayStack stack);

int Length(ArrayStack stack);

int IsEmptyStack(ArrayStack stack);

void *Push(ArrayStack stack, void *element);

void *Pop(ArrayStack stack);

void *GetTop(ArrayStack stack);

#endif //ARRAY_STACK_H
