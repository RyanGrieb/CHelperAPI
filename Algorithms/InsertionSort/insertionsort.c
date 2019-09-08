#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../StringManipulation/stringarray.h"

/* Insertion Sort
 * 
 * To properly visualize insertion sort, think of how we organize a deck of cards.
 * We go through the deck & sort from the beginning from the smallest number.
 *
 *
 */
int *insertionSort(int array[], int length){

	//Start at 0. Check if the elements behind it are greater than the num

	int i, currentNum, j;
	for(i = 1; i < length; i++){

		//Get the current num we want to sort in the array.
		currentNum = array[i];
		//Define our starting index. (From high to low).
		j = i - 1;

		//If our currentNum is still to high, shift down.
		while(j >= 0 && array[j] > currentNum){
			//Shift the whole array over to the right.
			array[j + 1] = array[j];
			j = j - 1;
		}

		//Put the current num at our determined index.
		array[j + 1] = currentNum;
	}

	return array;
}

int main(int arc, char** argv){
	//TODO: Im probally gonna make a custom typedef array so i dont have to manually get the size again.
	int *array = intArrayFromString(argv[1]);
	int arraySize = arraySizeFromString(argv[1]);
	printf("Before Sort:\n");
	printIntArray(array,arraySize);
	printf("After Sort:\n");
	printIntArray(insertionSort(array,arraySize), arraySize);	
	return 0;
}
