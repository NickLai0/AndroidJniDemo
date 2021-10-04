//
// Created by Nick Lai on 2021/10/3.
//

#include <malloc.h>
#include <stddef.h>
#include "LinkedQueue.h"

LinkedQueue InitQueue() {
    LinkedQueue queue = malloc(sizeof(LinkedQueueStructure));
    queue->size = 0;
    queue->front = queue->rear = NULL;
    return queue;
}


int IsEmptyQueue(LinkedQueue queue) {
    return queue->size == 0;
}

int Size(LinkedQueue queue) {
    return queue->size;
}

int Enqueue(LinkedQueue queue, void *element) {
    if (queue == NULL) {
        return -1;
    }
    LinkedQueueNode node = malloc(sizeof(LinkedQueueNodeStructure));
    node->element = element;
    node->next = NULL;
    if (queue->size == 0) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    int index = queue->size;
    queue->size++;
    return index;
}

void *Dequeue(LinkedQueue queue) {
    if (queue == NULL || queue->size == 0) {
        return NULL;
    }
    LinkedQueueNode node = queue->front;
    queue->front = node->next;
    queue->size--;
    void *element = node->element;
    free(node);
    if (queue->size == 0) {
        queue->rear = NULL;
    }
    return element;
}

void UninitQueue(LinkedQueue queue) {
    if (queue != NULL) {
        //Release all of nodes first;
        while (queue->size > 0) {
            Dequeue(queue);
        }
        free(queue);
    }
}

void *GetHead(LinkedQueue queue) {
    if (queue == NULL || queue->size == 0) {
        return NULL;
    }
    return queue->front->element;
}

int Add(LinkedQueue queue, void *element) {
    return Enqueue(queue, element);
}

void *Poll(LinkedQueue queue) {
    return Dequeue(queue);
}

void *Peek(LinkedQueue queue) {
    return GetHead(queue);
}

