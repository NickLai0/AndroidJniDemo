/*
 * studentsAverageScore.cpp
 *
 *  Created on: 2021Äê6ÔÂ28ÈÕ
 *      Author: Nick Lai
 */

#include <stdio.h>
#include <string.h>

#define N 100

typedef struct student{
    int number;
    char name[20];
    char sex;
    int score[3];
    
} STUDENT;

int getMaleCount(STUDENT *stu, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if((stu+i)->sex == 'M' || (stu+i)->sex == 'm') {
            count++;
        }
    }
    return count;
}

int getFemaleCount(STUDENT *stu, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if((stu+i)->sex == 'F' || (stu+i)->sex == 'f') {
            count++;
        }
    }
    return count;
}

float calcStudentAverageScore(STUDENT *stu, int n) {
	float sum;
	    for(int i = 0; i < n; i++) {
	    	sum += (stu+i)->score[0] + (stu+i)->score[1] + (stu+i)->score[2];
	    }
	    return sum / n;
}

int main(void) {
    STUDENT stu[N];
    int i,num, maleCount, femaleCount;
    float studentAverageScore = 0;
    printf("How many students do you wanna input:");
    scanf("%d",&num);
    printf("Input the following information:\n");
    printf("%-7s%-6s%-5s%-8s%-8s%-8s\n"
    ,"number","name","sex","score1","score2","score3");
    for(i = 0; i < num; i++) {
        scanf("%d %s %c %d %d %d"
        ,&stu[i].number, stu[i].name, &stu[i].sex
        ,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
    }
    maleCount = getMaleCount(stu,num);
    femaleCount = getFemaleCount(stu,num);
    studentAverageScore = calcStudentAverageScore(stu,num);
    printf("Male:%d\nFemale:%d\nStudent Adverage Score:%.1f\n"
    		,maleCount, femaleCount,studentAverageScore);
    return 0;
}



