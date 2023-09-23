//Importation of standard libraries
#include <stdio.h>//Standard input output
#include <stdlib.h>//standard library header file

int main() {
	//Declaration of variables
    int sizeA, sizeB, i, j, k, count = 0;
    
    //Get user inputs for the size of arrays
    printf("Enter the sizes of the arrays (separated by a comma): ");
    scanf("%d,%d", &sizeA, &sizeB);
    
    //Declaration of arrays
    int arrayA[sizeA], arrayB[sizeB], arrayC[sizeA+sizeB];
    
    //Get user inputs for Array A
    printf("Enter the elements of the first array: ");
    for (i = 0; i < sizeA; i++) {
        scanf("%d", &arrayA[i]);
        arrayC[i] = arrayA[i];
    }
    
    //Get user inputs for Array B
    printf("Enter the elements of the second array: ");
    for (i = 0; i < sizeB; i++) {
        scanf("%d", &arrayB[i]);
        arrayC[sizeA+i] = arrayB[i];
    }

	//Calculation of number of distinct arithmetic sequences
    int n = sizeA + sizeB;
    for (i = 0; i < n-2; i++) {
        for (j = i+1; j < n-1; j++) {
            int difference = arrayC[j] - arrayC[i];//Common difference of the elements
            int nextElement = arrayC[j] + difference;//expected value of the next element
            int sequence = 2;
            for (k = j+1; k < n; k++) {
                if (arrayC[k] == nextElement) {
                    sequence++;
                    nextElement += difference;
                }
            }
            if (sequence > 2) {
                count++;
            }
        }
    }

    printf("\nNumber of distinct arithmetic sequences that can be obtained: %d\n", count);
    return 0;
}

