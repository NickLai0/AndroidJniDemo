#include <stdio.h>

void getArray(){
	int arr[]={1,2,3,4,5};
	printf("&arr=%d, arr=%d", &arr, arr);
}

int main(void) { 
	getArray();
	return 0;
}

