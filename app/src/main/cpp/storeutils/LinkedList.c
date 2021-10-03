//
// Created by Nick Lai on 2021/10/1.
//

#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include "LinkedList.h"

LinkedList InitList() {
    LinkedList list = malloc(sizeof(LinkedListNodeStructure));
    list->size = 0;
    list->head = list->tail = NULL;
    return list;
}


void *DeleteByIndex(LinkedList list, int index) {
    if (list->size == 0 || index < 0 || index >= list->size) {
        return NULL;
    }
    LinkedListNodeStructure *tempNode = NULL;
    if (index == 0) {
        //Remove the old head.
        tempNode = list->head;
        list->head = list->head->next;
        //If list->head == NULL means there is no node.
        if (list->head != NULL) {
            //Still has node(s), so set the first node's previous field to NULL.
            list->head->previous = NULL;
        } else {
            list->tail = NULL;
        }
    } else if (index == list->size - 1) {
        //Remove the old tail.
        tempNode = list->tail;
        list->tail = list->tail->previous;
        list->tail->next = NULL;
    } else {
        //What you wanna find is in the middle of the list.
        int mid = list->size / 2;
        if (index < mid) {
            tempNode = list->head->next;
            int i = 1;
            while (i != index) {
                tempNode = tempNode->next;
                i++;
            }
        } else {
            tempNode = list->tail->previous;
            int i = list->size - 2;
            while (i != index) {
                tempNode = tempNode->previous;
                i--;
            }
        }
        tempNode->previous->next = tempNode->next;
        tempNode->next->previous = tempNode->previous;
    }
    void *tempElement = NULL;
    if (tempNode != NULL) {
        //Found one.
        tempElement = tempNode->element;
        //reduce one.
        list->size--;
        free(tempNode);
    }
    return tempElement;
}

void *Delete(LinkedList list, void *element) {
    if (list->size == 0) {
        return NULL;
    }
    LinkedListNodeStructure *tempNode = list->head;
    while (tempNode->element != element) {
        if (tempNode->next == NULL) {
            tempNode = NULL;
            break;
        }
        tempNode = tempNode->next;
    }
    void *tempElement = NULL;
    if (tempNode != NULL) {
        //Found one.
        if (tempNode == list->head && tempNode == list->tail) {
            list->head = list->tail = NULL;
        } else if (tempNode == list->head) {
            list->head = tempNode->next;
            list->head->previous = NULL;
        } else if (tempNode == list->tail) {
            list->tail = list->tail->previous;
            list->tail->next = NULL;
        } else {
            tempNode->previous->next = tempNode->next;
            tempNode->next->previous = tempNode->previous;
        }
        list->size--;
        tempElement = tempNode->element;
        free(tempNode);
    }
    return tempElement;
}

void Clear(LinkedList list) {
    while (list->size > 0) {
        DeleteByIndex(list, 0);
    }
//    list->length = 0;
}

void UninitList(LinkedList list) {
    if (list != NULL) {
        Clear(list);
        free(list);
    }
}

int size(LinkedList list) {
    return list->size;
}

int length(LinkedList list) {
    return INT32_MAX;
}

int Add(LinkedList list, void *element) {
    LinkedListNodeStructure *tempNode = malloc(sizeof(LinkedListNodeStructure));
    tempNode->element = element;
    tempNode->previous = tempNode->next = NULL;
    if (list->size == 0) {
        list->head = list->tail = tempNode;
    } else {
        tempNode->previous = list->tail;
        list->tail->next = tempNode;
        list->tail = tempNode;
    }
    list->size++;
    //Return the index of the new element.
    return (list->size - 1);
}

int Insert(LinkedList list, void *element, int index) {
    if (index < 0 || index > list->size) {
        //Link the element to the last.
        index = list->size;
    }
    LinkedListNodeStructure *newNode = malloc(sizeof(LinkedListNodeStructure));
    newNode->element = element;
    newNode->previous = newNode->next = NULL;
    if (list->size == 0) {
        list->head = list->tail = newNode;
    } else if (index == 0) {
        newNode->next = list->head;
        list->head->previous = newNode;
        list->head = newNode;
    } else if (index == list->size) {
        newNode->previous = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    } else {
        LinkedListNodeStructure *tempNode = NULL;
        if (index < list->size / 2) {
            tempNode = list->head->next;
            int i = 1;
            while (i != index) {
                tempNode = tempNode->next;
                i++;
            }
        } else {
            tempNode = list->tail->previous;
            int i = list->size - 2;
            while (i != index) {
                tempNode = tempNode->previous;
                i--;
            }
        }
        newNode->next = tempNode;
        newNode->previous = tempNode->previous;
        tempNode->previous->next = newNode;
        tempNode->previous = newNode;
    }
    list->size++;
    return index;
}

void *Get(LinkedList list, int index) {
    if (list->size == 0 || index < 0 || index >= list->size) {
        return NULL;
    }
    void *element = NULL;
    LinkedListNodeStructure *node = NULL;
    if (index < list->size / 2) {
        node = list->head;
        int i = 0;
        while (i != index) {
            node = node->next;
            i++;
        }
    } else {
        node = list->tail;
        int i = list->size - 1;
        while (i != index) {
            node = node->previous;
            i--;
        }
    }
    element = node->element;

    return element;
}

int IndexOf(LinkedList list, void *element) {
    if (list->size > 0) {
        LinkedListNodeStructure *node = list->head;
        int i = 0;
        while (i < list->size) {
            if (node->element == element) {
                return i;
            }
            node = node->next;
            i++;
        }
    }
    return -1;
}
