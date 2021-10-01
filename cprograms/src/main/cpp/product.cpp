/*
 * product.cpp
 *
 *  Created on: 2021Äê6ÔÂ29ÈÕ
 *      Author: Nick Lai
 */

#include <stdio.h>

//Maximum of products.
#define MAX 100

typedef struct product{
	int code; 		//Product unique code.
	char name[20];	//The name of the product, eg: pair.
	float price;	//The price of each KG.
	int number;		//How many KGs.
	double money;	//How much money for all KGs.
} PRODUCT;

void input(PRODUCT *p) {
	printf("The code of the produce:");
	scanf("%d",&(*p).code);
	getchar();
	
	printf("The name of the produce:");
	gets((*p).name);
	
	printf("The price of the produce:");
	scanf("%f",&(*p).price);
	
	printf("The number of the produce:");
	scanf("%d",&(*p).number);
	
	//Caculate the total money and then assign to money member variable.
	(*p).money = (*p).number * (*p).price;
}

void printProducts(PRODUCT *p, int num) {
	printf("code    name    price   number  total\n");
	for(int i =0; i < num; i++) {
		printf("%-7d %-7s %-7.2f %-7d %-7.2lf\n"
				,(p+i)->code
				,(p+i)->name
				,(p+i)->price
				,(p+i)->number
				,(p+i)->money
		);
	}
}	

void swap(PRODUCT *p1, PRODUCT *p2) {
	PRODUCT temp = *p1;
	*p1 = *p2;
	*p2= temp;
}

void sort(PRODUCT *p, int num) {
	//Sort n-1 times.
	PRODUCT *temp; 
	for(int i = 0; i < num - 1; i++) {
		//Each time compare n-i-1 times.
		for(int j = 0; j < num - i - 1; i++) {
			if((p+j)->money < (p+j+1)->money) {
				printf("sort-> temp=%d, p[j]=%d, p[j+1]=%d\n",temp, p[j], p[j+1]);
				swap(p+j,p+j+1);
				//temp = &p[j];
				//p[j]= p[j+1];
				//p[j+1] = *temp;
				printf("sort-> temp=%d, p[j]=%d, p[j+1]=%d\n",temp, p[j], p[j+1]);
			}
		}	
	}
}

int main(){
	PRODUCT productArr[MAX];
	int num;
	printf("How many products information do you wanna input: ");
	scanf("%d",&num);
	getchar();
	for(int i =0; i < num; i++) {
		//Get the address of i element in the array.
		input(&productArr[i]);
	}
	printf("\n");
	printf("Sorting the products by money.\n");
	for(int i = 0; i < num; i++) {
		printf("&arr[%d]=%d\n",i ,&productArr[i]);
	}
	sort(productArr, num);
	for(int i = 0; i < num; i++) {
		printf("arr[%d]=%d\n",i ,productArr[i]);
	}
	printf("After sorted:\n");
	printProducts(productArr, num);
}
