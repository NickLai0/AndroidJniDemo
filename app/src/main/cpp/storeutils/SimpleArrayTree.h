//
// Created by Nick Lai on 2021/10/4.
//
#include "ArrayList.h"

#ifndef SIMPLE_TREE_H
#define SIMPLE_TREE_H

typedef struct Node {
    //Available while traversing.
    int level;
    struct Node *parent;
    void *data;
    ArrayList children;
} SimpleArrayTreeNodeStructure, *SimpleArrayTreeNode;

SimpleArrayTreeNode Root(SimpleArrayTreeNode node);

void traverseTreeByRecursive(SimpleArrayTreeNode node,
                             void (*listener)(SimpleArrayTreeNode));

void traverse(int level, SimpleArrayTreeNode node,
              void (*listener)(SimpleArrayTreeNode));

void TraverseTreeByQueue(SimpleArrayTreeNode node,
                         void (*listener)(SimpleArrayTreeNode curNode));

int SizeOfChildren(SimpleArrayTreeNode node);

SimpleArrayTreeNode GetChild(SimpleArrayTreeNode node, int index);

void *DeleteChild(SimpleArrayTreeNode node, SimpleArrayTreeNode child);

int InsertChild(SimpleArrayTreeNode node, SimpleArrayTreeNode child, int index);

int AddChild(SimpleArrayTreeNode node, SimpleArrayTreeNode child);

SimpleArrayTreeNode Create(void *data);

SimpleArrayTreeNode Parent(SimpleArrayTreeNode node);

#endif //SIMPLE_TREE_H
