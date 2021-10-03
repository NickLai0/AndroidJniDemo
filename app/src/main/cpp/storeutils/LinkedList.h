//
// Created by Nick Lai on 2021/9/30.
//
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    void *element;
    struct node *previous;
    struct node *next;
} LinkedListNodeStructure;

typedef struct {
    int size;
    LinkedListNodeStructure *head;
    LinkedListNodeStructure *tail;
} *LinkedList;

LinkedList InitList();

void UninitList(LinkedList list);

int size(LinkedList list);

int length(LinkedList list);

int Add(LinkedList list, void *element);

int Insert(LinkedList list, void *element, int index);

void *Get(LinkedList list, int index);

int IndexOf(LinkedList list, void *element);

void *DeleteByIndex(LinkedList list, int index);

void *Delete(LinkedList list, void *element);

void Clear(LinkedList list);

#endif