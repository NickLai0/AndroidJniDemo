//
// Created by Nick Lai on 2021/9/30.
//

#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include "../storeutils/ArrayList.h"

void test1();

void test2();

void printArrayList(ArrayList list) {
    int *intPointer;
    //Test get function.
    for (int i = 0; i < Length(list); ++i) {
        intPointer = (int *) Get(list, i);
        printf("list[%d]=%d\n", i, *intPointer);
    }
    printf("length=%d, capacity=%d\n", Length(list), Capacity(list));
}

int main() {
    printf("Test 1 start--------------\n\n");
    test1();
    printf("\n\nTest 1 end----------------\n\n");
    printf("Test 2 start--------------\n\n");
    test2();
    printf("\n\nTest 2 start--------------\n\n");
    return 0;
}

typedef struct {
    char name[10];
    int age;
    char sex;
} Student, *StudentPtr;

void test2() {
    const int STUDENT_NUMBER = 3;
    Student stuArr[] = {{"Nick",  25, 'm'},
                        {"Elena", 18, 'f'},
                        {"Bob",   60, 'm'}};

    ArrayList list = InitList(8);
    for (int i = 0; i < STUDENT_NUMBER; ++i) {
        Add(list, &stuArr[i]);
    }

    StudentPtr stuPtr = NULL;
    for (int i = 0; i < STUDENT_NUMBER; ++i) {
        stuPtr = Delete(list, &stuArr[i]);
        if (stuPtr != NULL) {
            printf("student %d:%s,%d,%c\n", i + 1, stuPtr->name, stuPtr->age, stuPtr->sex);
        }
    }

    UninitList(list);
}

void test1() {
    const int INIT_SIZE = 8;
    ArrayList list = InitList(INIT_SIZE);
    int *intPointer;

    //Test add function.
    for (int i = 1; i <= INIT_SIZE; i++) {
        intPointer = malloc(sizeof(int));
        *intPointer = i * 100;
        Add(list, intPointer);
    }

    //Test insert function.
    intPointer = malloc(sizeof(int));
    *intPointer = 0;
    Insert(list, intPointer, 0);
    printArrayList(list);

    printf("\nTest insert -1 and bigger than the length of ArrayList start ---------------:\n");

    intPointer = malloc(sizeof(int));
    *intPointer = -1;
    Insert(list, intPointer, -1);

    intPointer = malloc(sizeof(int));
    *intPointer = INT32_MAX;
    Insert(list, intPointer, -1);

    printArrayList(list);

    printf("Test insert -1 and bigger than the length of ArrayList end -----------------:\n");

    printf("\nValue %d at index of %d\n", *intPointer, IndexOf(list, intPointer));

    printf("\nDelete %d from list.%s\n", *intPointer,
           Delete(list, intPointer) == NULL ? "failed!" : "Success!");
    printArrayList(list);
    //Free the memory of this variable from the heap.
    free(intPointer);

    intPointer = malloc(sizeof(int *));
    *intPointer = 11111111;
    printf("\nDelete %d from list.%s\n", *intPointer,
           Delete(list, intPointer) == NULL ? "failed!" : "Success!");
    printArrayList(list);
    free(intPointer);

    //Free all of memory from the heap.
    for (int i = 0; i < Length(list); ++i) {
        intPointer = (int *) Get(list, i);
        free(intPointer);
    }
    UninitList(list);
}
