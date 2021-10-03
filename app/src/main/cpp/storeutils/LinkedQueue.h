//
// Created by Nick Lai on 2021/10/3.
//

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

typedef struct node {
    void *element;
    struct node *next;
} LinkedQueueNodeStructure, *LinkedQueueNode;

typedef struct {
    int size;
    LinkedQueueNodeStructure *front, *rear;
} LinkedQueueStructure, *LinkedQueue;

LinkedQueue InitQueue();

void UninitQueue(LinkedQueue queue);

int IsEmptyQueue(LinkedQueue queue);

int Size(LinkedQueue queue);

void Enqueue(LinkedQueue queue, void *element);

void *Dequeue(LinkedQueue queue);

void *GetHead(LinkedQueue queue);

void Add(LinkedQueue queue, void *element);

void *Poll(LinkedQueue queue);

void *Peek(LinkedQueue queue);

#endif //LINKED_QUEUE_H
