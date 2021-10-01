//
// Created by Nick Lai on 2021/9/30.
//
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
    int length;
    int capacity;
    void **elements;
} ArrayListStructure, *ArrayList;

ArrayList initiate(int size);

void uninitiate(ArrayList arrayList);

int length(ArrayList arrayList);

int capacity(ArrayList arrayList);

int add(ArrayList arrayList, void *element);

int insert(ArrayList arrayList, void *element, int index);

void *get(ArrayList arrayList, int index);

int indexOf(ArrayList list, void *element);

void *deleteByIndex(ArrayList list, int index);

void *delete(ArrayList list, void *element);

#endif