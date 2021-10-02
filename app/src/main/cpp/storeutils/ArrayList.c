//
// Created by Nick Lai on 2021/9/30.
//

#include "ArrayList.h"
//You have to add the file in the project,
//otherwise, you can not access the
//standard libraries.
#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>

/**
 * size should be larger or equals to 8, otherwise,
 * it would be set to 8 automatically.
 * @param size an integer that larger or equals to 8
 */
ArrayList InitList(int size) {
    ArrayList list = malloc(sizeof(ArrayListStructure));
    if (size < 8) {
        size = 8;
    }
    list->size = 0;
    list->len = size;
    list->elements = malloc(size * sizeof(void *));
    return list;
    //printf("initiate-> size=%d, size * sizeof(void *) = %d", size, size * sizeof(void *));
}

void UninitList(ArrayList list) {
    if (list != NULL) {
        free(list->elements);
        free(list);
        //printf("uninitiate-> list freed.");
    }
}

int IndexOf(ArrayList list, void *element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->elements[i] == element) {
            return i;
        }
    }
    return -1;
}

int size(ArrayList list) { return list->size; }

int length(ArrayList list) { return list->len; }

int Insert(ArrayList list, void *element, int index) {
    if (list->size + 1 > list->len) {
        //Make a bigger array.
        int newCapacity = list->len + list->len / 2;
        void **newElements = malloc(newCapacity * sizeof(void *));
        memcpy(newElements, list->elements, sizeof(void *) * list->size);
        free(list->elements);
        //Assign with new values.
        list->elements = newElements;
        list->len = newCapacity;
    }
    if (index < 0 || index > list->size) {
        index = list->size;
    }
    if (index < list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->elements[i + 1] = list->elements[i];
        }
    }
    list->elements[index] = element;
    list->size++;
    return index;
}

int Add(ArrayList list, void *element) {
    return Insert(list, element, list->size);
}

void *DeleteByIndex(ArrayList list, int index) {
    void *temp = NULL;
    if (index >= 0 && index < list->size) {
        temp = list->elements[index];
        for (int i = index; i < list->size - 1; ++i) {
            list->elements[i] = list->elements[i + 1];
        }
        list->size--;
    }
    return temp;
}

void *Delete(ArrayList list, void *element) {
    return DeleteByIndex(list, IndexOf(list, element));
}

void *Get(ArrayList list, int index) {
    if (index >= 0 && index < list->size) {
        return list->elements[index];
    }
    return NULL;
}

void Clear(ArrayList list) {
    list->size = 0;
}