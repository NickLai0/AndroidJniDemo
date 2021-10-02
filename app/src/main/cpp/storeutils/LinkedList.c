//
// Created by Nick Lai on 2021/10/1.
//

#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include "LinkedList.h"

LinkedList InitList() {
    LinkedList list = malloc(sizeof(LinkedListNode));
    list->length = 0;
    list->head = list->tail = NULL;
    return list;
}


void *DeleteByIndex(LinkedList list, int index) {
    if (list->length == 0 || index < 0 || index >= list->length) {
        return NULL;
    }
    LinkedListNode *tempNode = NULL;
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
    } else if (index == list->length - 1) {
        //Remove the old tail.
        tempNode = list->tail;
        list->tail = list->tail->previous;
        list->tail->next = NULL;
    } else {
        //What you wanna find is in the middle of the list.
        int mid = list->length / 2;
        if (index < mid) {
            tempNode = list->head->next;
            int i = 1;
            while (i != index) {
                tempNode = tempNode->next;
                i++;
            }
        } else {
            tempNode = list->tail->previous;
            int i = list->length - 2;
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
        list->length--;
        free(tempNode);
    }
    return tempElement;
}

void *Delete(LinkedList list, void *element) {
    if (list->length == 0) {
        return NULL;
    }
    LinkedListNode *tempNode = list->head;
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
        list->length--;
        tempElement = tempNode->element;
        free(tempNode);
    }
    return tempElement;
}

void Clear(LinkedList list) {
    while (list->length > 0) {
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

int Length(LinkedList list) {
    return list->length;
}

int Capacity(LinkedList list) {
    return INT32_MAX;
}

int Add(LinkedList list, void *element) {
    LinkedListNode *tempNode = malloc(sizeof(LinkedListNode));
    tempNode->element = element;
    tempNode->previous = tempNode->next = NULL;
    if (list->length == 0) {
        list->head = list->tail = tempNode;
    } else {
        tempNode->previous = list->tail;
        list->tail->next = tempNode;
        list->tail = tempNode;
    }
    list->length++;
    //Return the index of the new element.
    return (list->length - 1);
}

int Insert(LinkedList list, void *element, int index) {
    if (index < 0 || index > list->length) {
        //Link the element to the last.
        index = list->length;
    }
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->element = element;
    newNode->previous = newNode->next = NULL;
    if (list->length == 0) {
        list->head = list->tail = newNode;
    } else if (index == 0) {
        newNode->next = list->head;
        list->head->previous = newNode;
        list->head = newNode;
    } else if (index == list->length) {
        newNode->previous = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    } else {
        LinkedListNode *tempNode = NULL;
        if (index < list->length / 2) {
            tempNode = list->head->next;
            int i = 1;
            while (i != index) {
                tempNode = tempNode->next;
                i++;
            }
        } else {
            tempNode = list->tail->previous;
            int i = list->length - 2;
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
    list->length++;
    return index;
}

void *Get(LinkedList list, int index) {
    if (list->length == 0 || index < 0 || index >= list->length) {
        return NULL;
    }
    void *element = NULL;
    LinkedListNode *node = NULL;
    if (index < list->length / 2) {
        node = list->head;
        int i = 0;
        while (i != index) {
            node = node->next;
            i++;
        }
    } else {
        node = list->tail;
        int i = list->length - 1;
        while (i != index) {
            node = node->previous;
            i--;
        }
    }
    element = node->element;

    return element;
}

int IndexOf(LinkedList list, void *element) {
    if (list->length > 0) {
        LinkedListNode *node = list->head;
        int i = 0;
        while (i < list->length) {
            if (node->element == element) {
                return i;
            }
            node = node->next;
            i++;
        }
    }
    return -1;
}
