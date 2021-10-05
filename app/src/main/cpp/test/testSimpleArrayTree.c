//
// Created by Nick Lai on 2021/10/4.
//

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include "../storeutils/SimpleArrayTree.h"

void printSimpleTreeByQueue(SimpleArrayTreeNode rootNode);

void printSimpleTreeByRecursive(SimpleArrayTreeNode pNode);

void test1() {
    SimpleArrayTreeNode node = NULL;
    printf("Before using NULL pointer...\n");
    printf("%d\n", node->parent);
    printf("Use NULL pointer afterward...\n");
}

void test2() {
    for (int i = 0; i < 1; i++) {
        printf("test2 -> for (int i = 0; i < 1; i++)");
    }
}

int main() {
//    test1();
//    test2();

    SimpleArrayTreeNode node0 = Create("Node0");
    {
        SimpleArrayTreeNode node00 = Create("Node00");
        AddChild(node0, node00);
        {
            SimpleArrayTreeNode node000 = Create("Node000");
            SimpleArrayTreeNode node001 = Create("Node001");
            SimpleArrayTreeNode node002 = Create("Node002");
            AddChild(node00, node000);
            AddChild(node00, node001);
            AddChild(node00, node002);
        }

        SimpleArrayTreeNode node01 = Create("Node01");
        AddChild(node0, node01);
        {
            SimpleArrayTreeNode node010 = Create("Node010");
            SimpleArrayTreeNode node011 = Create("Node011");
            SimpleArrayTreeNode node012 = Create("Node012");
            AddChild(node01, node010);
            AddChild(node01, node011);
            AddChild(node01, node012);
        }

        SimpleArrayTreeNode node02 = Create("Node02");
        AddChild(node0, node02);
        {
            SimpleArrayTreeNode node020 = Create("node020");
            SimpleArrayTreeNode node021 = Create("node021");
            SimpleArrayTreeNode node022 = Create("node022");
            AddChild(node02, node020);
            AddChild(node02, node021);
            AddChild(node02, node022);
        }
    }
    //printSimpleTreeByQueue(node0);
    printSimpleTreeByRecursive(node0);

    SimpleArrayTreeNode testNode = Create("test");
    printf("Insert node of %s\n", testNode->data);
    InsertChild(node0, testNode, 0);
    printSimpleTreeByRecursive(node0);

    printf("The root node is: %s\n", Root(testNode)->data);

    printf("Delete node: %s\n", testNode->data);
    DeleteChild(node0, testNode);
    printSimpleTreeByRecursive(node0);

    return 0;
}

void traverseTreeListener(SimpleArrayTreeNode curNode) {
    int space = curNode->level * 6;
    for (int i = 0; i < space; ++i) {
        putchar(' ');
    }
    printf("%s\n", curNode->data);
}

void printSimpleTreeByRecursive(SimpleArrayTreeNode rootNode) {
    if (rootNode == NULL) {
        printf("printSimpleTreeByRecursive-> argument rootNode is NULL.\n");
        return;
    }
    printf("printSimpleTreeByRecursive----------------start-----------------\n");
    traverseTreeByRecursive(rootNode, &traverseTreeListener);
    printf("printSimpleTreeByRecursive------------------end-----------------\n");
}


void printSimpleTreeByQueue(SimpleArrayTreeNode rootNode) {
    if (rootNode == NULL) {
        printf("printSimpleTreeByQueue-> argument rootNode is NULL.\n");
        return;
    }
    printf("printSimpleTreeByQueue----------------start-----------------\n");
    TraverseTreeByQueue(rootNode, &traverseTreeListener);
    printf("printSimpleTreeByQueue------------------end-----------------\n");
}
