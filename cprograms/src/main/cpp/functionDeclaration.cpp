/*
 * functionDeclaration.cpp
 *
 *  Created on: 2021Äê6ÔÂ26ÈÕ
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


