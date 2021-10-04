//
// Created by Nick Lai on 2021/10/2.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H


typedef struct node {
    void *element;
    struct node *next;
} LinkedStackNodeStructure, *LinkedStackNodePointer;

typedef struct {
    //The top of the stack;
    LinkedStackNodeStructure *top;
    int size;
} LinkedStackStructure, *LinkedStack;

LinkedStack InitStack();

void UninitStack(LinkedStack stack);

int Size(LinkedStack stack);

int Length(LinkedStack stack);

int IsEmptyStack(LinkedStack stack);

void *Push(LinkedStack stack, void *element);

void *Pop(LinkedStack stack);

void *GetTop(LinkedStack stack);

#endif //LINKEDSTACK_H
