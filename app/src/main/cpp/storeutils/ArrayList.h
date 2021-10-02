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

ArrayList Initiate(int size);

void Uninitiate(ArrayList list);

int Length(ArrayList list);

int Capacity(ArrayList list);

int Add(ArrayList list, void *element);

int Insert(ArrayList list, void *element, int index);

void *Get(ArrayList list, int index);

int IndexOf(ArrayList list, void *element);

void *DeleteByIndex(ArrayList list, int index);

void *Delete(ArrayList list, void *element);

void Clear(ArrayList list);

#endif