#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printIntArray(int* array, int length)
{
    int i;
    printf("[");
    for (i = 0; i < length; i++) {
        printf(((i >= length - 1) ? "%d" : "%d,"), array[i]);
    }
    printf("]\n");
}

int* intArrayFromString(char* input)
{
    //TODO: Check if we have a valid string format
    //TODO: Make more effiecent
    //TODO: Reformat to not look like crap.;

    unsigned long i;
    unsigned long inputLength = strlen(input);
    unsigned long currentNumLength = 0;
    int arrayIndex = 0;
    char currentNum[256];

    int* array = (int*)malloc(inputLength * sizeof(int));

    for (i = 0; i < inputLength; i++) {
        if (input[i] != ',') {
            currentNum[currentNumLength] = input[i];
            currentNumLength++;
        }

        if (input[i] == ',' || i >= inputLength - 1) {
            currentNum[currentNumLength + 1] = '\0';
            array[arrayIndex] = atoi(currentNum);
            memset(currentNum, 0, currentNumLength);
            arrayIndex++;
            currentNumLength = 0;
        }
    }
    return array;
}

int arraySizeFromString(char* input)
{
    int size = 0;

    unsigned long i;
    unsigned long inputLength = strlen(input);
    for (i = 0; i < inputLength; i++)
        if (input[i] == ',' || i >= inputLength)
            size++;

    return (size == 0) ? 0 : size + 1;
}
