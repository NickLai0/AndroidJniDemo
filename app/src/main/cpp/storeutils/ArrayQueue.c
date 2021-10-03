//
// Created by Nick Lai on 2021/10/2.
//

#include <malloc.h>
#include <string.h>
#include <stddef.h>
#include "ArrayQueue.h"

ArrayQueue InitQueue(int initLength) {
    ArrayQueue queue = malloc(sizeof(ArrayQueueStruct));
    if (initLength < 8) {
        initLength = 8;
    }
    queue->data = malloc(initLength * sizeof(void *));
    queue->length = initLength;
    queue->front = queue->rear = 0;
    return queue;

}

void UninitQueue(ArrayQueue queue) {
    if (queue != NULL) {
        free(queue->data);
        free(queue);
    }
}

int IsEmptyQueue(ArrayQueue queue) {
    return queue->front == queue->rear;
}

int Size(ArrayQueue queue) {
    return (queue->rear - queue->front + queue->length) % queue->length;
//    if (queue->front == queue->rear) {
//        return 0;
//    } else if (queue->rear > queue->front) {
//        return queue->rear - queue->front;
//    } else {
//        return queue->rear - queue->front + queue->length;
//    }
}

void Enqueue(ArrayQueue queue, void *element) {
    if (Size(queue) == queue->length - 1) {//There is no space for the new element.
        int newLength = queue->length + queue->length / 2;
        void **newData = malloc(newLength * sizeof(void *));
        memcpy(newData, queue->data, queue->length * sizeof(void *));
        free(queue->data);
        queue->data = newData;
        queue->length = newLength;
    }
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % queue->length;
}

void *Dequeue(ArrayQueue queue) {
    void *element = NULL;
    if (queue->front != queue->rear) {
        element = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->length;
    }
    return element;
}

void *GetHead(ArrayQueue queue) {
    if (queue->front != queue->rear) {
        return queue->data[queue->front];
    }
    return NULL;
}

void Add(ArrayQueue queue, void *element) {
    Enqueue(queue, element);
}

void *Poll(ArrayQueue queue) {
    return Dequeue(queue);
}

void *Peek(ArrayQueue queue) {
    return GetHead(queue);
}

