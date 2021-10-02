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
ArrayList Initiate(int size) {
    ArrayList list = malloc(sizeof(ArrayListStructure));
    if (size < 8) {
        size = 8;
    }
    list->length = 0;
    list->capacity = size;
    list->elements = malloc(size * sizeof(void *));
    return list;
    //printf("initiate-> size=%d, size * sizeof(void *) = %d", size, size * sizeof(void *));
}

void Uninitiate(ArrayList list) {
    if (list != NULL) {
        free(list);
        //printf("uninitiate-> list freed.");
    }
}

int IndexOf(ArrayList list, void *element) {
    for (int i = 0; i < list->length; ++i) {
        if (list->elements[i] == element) {
            return i;
        }
    }
    return -1;
}

int Length(ArrayList list) { return list->length; }

int Capacity(ArrayList list) { return list->capacity; }

int Insert(ArrayList list, void *element, int index) {
    if (list->length + 1 > list->capacity) {
        //Make a bigger array.
        int newCapacity = list->capacity + list->capacity / 2;
        void **newElements = malloc(newCapacity * sizeof(void *));
        memcpy(newElements, list->elements, sizeof(void *) * list->length);
        free(list->elements);
        //Assign with new values.
        list->elements = newElements;
        list->capacity = newCapacity;
    }
    if (index < 0 || index > list->length) {
        index = list->length;
    }
    if (index < list->length) {
        for (int i = list->length - 1; i >= index; i--) {
            list->elements[i + 1] = list->elements[i];
        }
    }
    list->elements[index] = element;
    list->length++;
    return index;
}

int Add(ArrayList list, void *element) {
    return Insert(list, element, list->length);
}

void *DeleteByIndex(ArrayList list, int index) {
    void *temp = NULL;
    if (index >= 0 && index < list->length) {
        temp = list->elements[index];
        for (int i = index; i < list->length - 1; ++i) {
            list->elements[i] = list->elements[i + 1];
        }
        list->length--;
    }
    return temp;
}

void *Delete(ArrayList list, void *element) {
    return DeleteByIndex(list, IndexOf(list, element));
}

void *Get(ArrayList list, int index) {
    if (index >= 0 && index < list->length) {
        return list->elements[index];
    }
    return NULL;
}

void Clear(ArrayList list) {
    list->length = 0;
}