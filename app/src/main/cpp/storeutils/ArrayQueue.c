//
// Created by Nick Lai on 2021/10/2.
//

#include <malloc.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
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
    if (queue == NULL) { return 1; }
    return queue->front == queue->rear;
}

int Size(ArrayQueue queue) {
    if (queue == NULL) { return -1; }
//    printf("length=%d, rear=%d, front=%d\n",
//           queue->length, queue->rear, queue->front);
    return (queue->length + queue->rear - queue->front) % queue->length;
}

int Enqueue(ArrayQueue queue, void *element) {
    if (queue == NULL) {
        return -1;
    }
    if (Size(queue) == queue->length - 1) {//There is no space for the new element.
        int newLength = queue->length + queue->length / 2;
        void **newData = malloc(newLength * sizeof(void *));
        for (int i = 0, j = queue->front; i < queue->length; ++i, j = (j + 1) % queue->length) {
            newData[i] = queue->data[j];
        }
        free(queue->data);
        queue->data = newData;
        queue->front = 0;
        queue->rear = queue->length - 1;
        queue->length = newLength;
    }
    queue->data[queue->rear] = element;
    int index = queue->rear;
    queue->rear = (queue->rear + 1) % queue->length;
    return index;
}

void *Dequeue(ArrayQueue queue) {
    if (queue == NULL) {
        return NULL;
    }
    void *element = NULL;
    if (queue->front != queue->rear) {
        element = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->length;
    }
    return element;
}

void *GetHead(ArrayQueue queue) {
    if (queue != NULL) {
        if (queue->front != queue->rear) {
            return queue->data[queue->front];
        }
    }
    return NULL;
}

int Add(ArrayQueue queue, void *element) {
    return Enqueue(queue, element);
}

void *Poll(ArrayQueue queue) {
    return Dequeue(queue);
}

void *Peek(ArrayQueue queue) {
    return GetHead(queue);
}

