/*
 * functionDeclaration.cpp
 *
 *  Created on: 2021��6��26��
 *      Author: Nick Lai
 */

#include <stdio.h>

//Declare a function before the main function.
//void helloWorld(); 

int main(){
	//Declare a function in the main function.
	void helloWorld(); 
	helloWorld();
	return 0;
}

void helloWorld(){
	printf("Hello World!");
}


