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

void Enqueue(LinkedQueue queue, void *element) {
    LinkedQueueNode node = malloc(sizeof(LinkedQueueNodeStructure));
    node->element = element;
    node->next = NULL;
    if (queue->size == 0) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

void *Dequeue(LinkedQueue queue) {
    if (queue->size == 0) {
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
    if (queue->size == 0) {
        return NULL;
    }
    return queue->front->element;
}

void Add(LinkedQueue queue, void *element) {
    Enqueue(queue, element);
}

void *Poll(LinkedQueue queue) {
    return Dequeue(queue);
}

void *Peek(LinkedQueue queue) {
    return GetHead(queue);
}

