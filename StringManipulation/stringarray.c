#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printIntArray(int *array, int length) {
        int i;
        printf("[");
        for(i = 0; i < length; i++){
                char *printFormat = ((i >= length - 1) ? "%d" : "%d,");
                printf(printFormat, array[i]);
        }
        printf("]\n");
}

int *intArrayFromString(char *input){
        //TODO: Check if we have a valid string format
        //TODO: Make more effiecent
        //TODO: Reformat to not look like crap.;

        int i;
        int arrayIndex = 0;
        int inputLength = strlen(input);
        char currentNum[256];

        int *array = (int *) malloc(inputLength * sizeof(int));

        for(i = 0; i < inputLength; i++){
                if(input[i] == ',')
                {
                        currentNum[strlen(currentNum) + 1] = '\0';
                        array[arrayIndex] = atoi(currentNum);
                        strcpy(currentNum, "");
                        arrayIndex++;
                } else {
                        currentNum[strlen(currentNum)] = input[i];
                        if(i >= inputLength - 1)
                        {
                                currentNum[strlen(currentNum) + 1] = '\0';
                                array[arrayIndex] = atoi(currentNum);
                        }

                }
        }
return array;
}

int arraySizeFromString(char* input){
        int i;
        int size = 0;
        int inputLength = strlen(input);
        for(i = 0; i < inputLength; i++)
                if(input[i] == ',' || i >= inputLength)
                        size++;

        return (size == 0) ? 0 : size + 1;
}


