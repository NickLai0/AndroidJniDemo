/*
 * product2.cpp
 *
 *  Created on: 2021年6月29日
 *      Author: Nick Lai
 */

#include <stdio.h>
#include <stdlib.h>

//Maximum of products.
#define MAX 100

typedef struct product{
	int code; 		//Product unique code.
	char name[20];	//The name of the product, eg: pair.
	float price;	//The price of each KG.
	int number;		//How many KGs.
	double money;	//How much money for all KGs.
} PRODUCT;

PRODUCT *input() {
	PRODUCT *p=(PRODUCT*)malloc(sizeof(PRODUCT));
	printf("The code of the product:");
	scanf("%d",&(*p).code);
	//Can not remove this, otherwise, gets() will get the '\n' as a string. 
	getchar();
	
	printf("The name of the product:");
	gets((*p).name);
	
	printf("The price of the product:");
	scanf("%f",&(*p).price);
	
	printf("The number of the product:");
	scanf("%d",&(*p).number);
	
	//Caculate the total money and then assign to money member variable.
	(*p).money = (*p).number * (*p).price;
	return p;
}

void printProducts(PRODUCT *p[], int num) {
	printf("*p[]=%d\n",sizeof(p));
	printf("code    name    price   number  total\n");
	for(int i =0; i < num; i++) {
		printf("%-7d %-7s %-7.2f %-7d %-7.2lf\n"
				,(*(p+i))->code
				,(*(p+i))->name
				,(*(p+i))->price
				,(*(p+i))->number
				,(*(p+i))->money
		);
	}
}	

void swap(PRODUCT *p1, PRODUCT *p2) {
	PRODUCT temp = *p1;
	*p1 = *p2;
	*p2= temp;
}

void sort(PRODUCT *pArr[], int num) {
	PRODUCT *temp;
	//Sort n-1 times.
	for(int i = 0; i < num - 1; i++) {
		//Each time compare n-i-1 times.
		for(int j = 0; j < num - i - 1; i++) {
			if(pArr[j]->money < pArr[j+1]->money) {
				//swap(p+j,p+j+1);
				temp =pArr[j];
				pArr[j]= pArr[j+1];
				pArr[j+1] = temp;
			}
		}	
	}
}

int main(){
	PRODUCT *productArr[MAX];
	printf("*p[]=%d\n",sizeof(productArr));
	int num;
	printf("How many products information do you wanna input: ");
	scanf("%d",&num);
	getchar();
	for(int i =0; i < num; i++) {
		//Get the address of i element in the array.
		productArr[i] = input();
	}
	
	printf("\n");
	printf("Sorting the products by money.\n");
	sort(productArr, num);
	printf("After sorted:\n");
	printProducts(productArr, num);
	
	return 0;
}



