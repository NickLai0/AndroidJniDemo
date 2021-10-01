/*
 * removeRandomRepeatedCharacters.cpp
 *
 *  Created on: 2021Äê6ÔÂ27ÈÕ
 *      Author: Nick Lai
 */


#include <stdio.h>
#include <stdlib.h>

#define LEN  40
int arr[LEN];

void printArr(int num[], const int N) {
	for(int i = 0; i < N; i++) {
		printf("%4d", num[i]);
		if((i+1) % 10 == 0){
			printf("\n");	
		}
	}
	printf("\n");	
}

void sort(int num[], const int N){
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < (N - i -1); j++) {
			if(num[j] > num[j+1]) {
				int temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
}

int removeRepeatedNum(int num[], const int N){
	int position=1, temp=num[0];
	for(int i = 1; i < N; i++) {
		if(temp != num[i]) {
			num[position] = num[i];
			temp = num[position];
			position++;
		}
	}
	return position;
}

int main(void) {
	for (int i; i < LEN; i++) {
		arr[i]=rand() % LEN;
	}
	sort(arr,LEN);
	printArr(arr,LEN);
	int newLen = removeRepeatedNum(arr,LEN);
	printArr(arr,newLen);
}
