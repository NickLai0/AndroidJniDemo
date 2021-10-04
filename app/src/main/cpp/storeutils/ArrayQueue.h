//
// Created by Nick Lai on 2021/10/2.
//

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct {
    void **data;
    int length;
    int front;
    int rear;
} ArrayQueueStruct, *ArrayQueue;

ArrayQueue InitQueue(int initLength);

void UninitQueue(ArrayQueue queue);

int IsEmptyQueue(ArrayQueue queue);

int Size(ArrayQueue queue);

int Enqueue(ArrayQueue queue, void *element);

void *Dequeue(ArrayQueue queue);

void *GetHead(ArrayQueue queue);

int Add(ArrayQueue queue, void *element);

void *Poll(ArrayQueue queue);

void *Peek(ArrayQueue queue);

#endif //ARRAY_QUEUE_H
