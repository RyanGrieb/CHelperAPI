#include <stdio.h>
#include "../../StringManipulation/stringarray.h"

void swap(int *x1, int *x2){
	int temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}

int *selectionSort(int array[], int length){
	int i,j,minNumIndex;

	for(i = 0; i < length - 1; i++){
		minNumIndex = i;
		for(j = i+1; j < length; j++)
			if(array[j] < array[minNumIndex])
				minNumIndex = j;

		swap(&array[minNumIndex],&array[i]);
	}

	return array;
}

int main(int argc, char** argv){
	int *array = intArrayFromString(argv[1]);
	int arraySize = arraySizeFromString(argv[1]);
	printf("Before Sort:\n");
	printIntArray(array,arraySize);
	printf("After Sort:\n");
	printIntArray(selectionSort(array,arraySize), arraySize);	
}

