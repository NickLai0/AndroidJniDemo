//
// Created by Nick Lai on 2021/9/30.
//
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
    int size;
    int len;
    void **elements;
} ArrayListStructure, *ArrayList;

ArrayList InitList(int size);

void UninitList(ArrayList list);

int LSize(ArrayList list);

int Length(ArrayList list);

int LAdd(ArrayList list, void *element);

int Insert(ArrayList list, void *element, int index);

void *Get(ArrayList list, int index);

int IndexOf(ArrayList list, void *element);

void *DeleteByIndex(ArrayList list, int index);

void *Delete(ArrayList list, void *element);

void Clear(ArrayList list);

#endif