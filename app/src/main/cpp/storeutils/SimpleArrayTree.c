//
// Created by Nick Lai on 2021/10/4.
//
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include "ArrayList.h"
#include "LinkedQueue.h"
#include "SimpleArrayTree.h"

SimpleArrayTreeNode Root(SimpleArrayTreeNode node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->parent == NULL) {
        return node;
    }
    return Root(node->parent);
}

SimpleArrayTreeNode Parent(SimpleArrayTreeNode node) {
    if (node == NULL) {
        return NULL;
    }
    return node->parent;
}

SimpleArrayTreeNode GetChild(SimpleArrayTreeNode node, int index) {
    if (node == NULL) {
        return NULL;
    }
    return Get(node->children, index);
}

SimpleArrayTreeNode Create(void *data) {
    SimpleArrayTreeNode node = malloc(sizeof(SimpleArrayTreeNodeStructure));
    node->parent = NULL;
    node->data = data;
    node->children = InitList(8);
    return node;
}


int AddChild(SimpleArrayTreeNode node, SimpleArrayTreeNode child) {
    if (node == NULL || child == NULL || child->parent != NULL) {
        return -1;
    }
    //Should I judge whether child is NULL?
    int insertedIndex = LAdd(node->children, child);
    if (insertedIndex > -1) {
        //Associate with parent node;
        child->parent = node;
    }
    return insertedIndex;
}

int InsertChild(SimpleArrayTreeNode node,
                SimpleArrayTreeNode child, int index) {
    if (node == NULL || child == NULL || child->parent != NULL) {
        return -1;
    }
    int insertedIndex = Insert(node->children, child, index);
    if (insertedIndex > -1) {
        //Associate with parent node;
        child->parent = node;
    }
    return insertedIndex;
}

void *DeleteChild(SimpleArrayTreeNode node, SimpleArrayTreeNode child) {
    if (node == NULL || child == NULL || child->parent != node) {
        return NULL;
    }
    SimpleArrayTreeNode tempNode = Delete(node->children, child);
    if (tempNode == child) {
        //child has been deleted. So set parent field to NULL;
        child->parent = NULL;
    }
    return tempNode;
}

int SizeOfChildren(SimpleArrayTreeNode node) {
    if (node == NULL) {
        return -1;
    }
    LSize(node->children);
}

void TraverseTreeByQueue(SimpleArrayTreeNode node,
                         void (*listener)(SimpleArrayTreeNode curNode)) {
    if (node == NULL || listener == NULL) {
        return;
    }
    LinkedQueue queue = InitQueue();

    node->level = 0;
    (*listener)(node);
    Enqueue(queue, node);

    while ((node = Dequeue(queue)) != NULL) {
        int childrenLevel = node->level + 1;
        int size = SizeOfChildren(node);
        for (int i = 0; i < size; ++i) {
            SimpleArrayTreeNode tempNode = GetChild(node, i);
            tempNode->level = childrenLevel;
            (*listener)(tempNode);
            Enqueue(queue, tempNode);
        }
    }

    UninitQueue(queue);
}

void traverse(int level, SimpleArrayTreeNode node,
              void (*listener)(SimpleArrayTreeNode)) {
    if (node == NULL || listener == NULL) {
        printf("node == NULL || listener == NULL)\n");
        return;
    }
    node->level = level;
    (*listener)(node);

    int nextLevel = level + 1;
    int size = SizeOfChildren(node);
    SimpleArrayTreeNode tempNode;
    for (int i = 0; i < size; i++) {
        tempNode = Get(node->children, i);
        traverse(nextLevel, tempNode, listener);
    }
}

void traverseTreeByRecursive(SimpleArrayTreeNode node,
                             void (*listener)(SimpleArrayTreeNode)) {
    traverse(0, node, listener);
}

