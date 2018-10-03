#include <stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"


int total_elements(int num_arrays, int* sizes) { // The number of arrays is the size of sizes
        int total_elements = 0;

        for(int i = 0; i < num_arrays; i++) {	// Loop to the number of arrays in multidimensional array
        total_elements += sizes[i];		// Sum the elements in sizes
        }
	return total_elements;
}

bool contains_element(int element, int size, int* array) {
        bool contains = false;

        for (int i = 0; i < size; i++){		// Loop to the size of the array

                if (array[i] == element){	// If the array[i] matches the element
                contains = true;		// It contains the element
                }
        }
        return contains;
}



int* array_merge(int num_arrays, int* sizes, int** values) { 
	int max_size = total_elements(num_arrays,sizes);    		// Returns total number of elements in multidimensional array
	int unique_count = 0;				     		// Keeps track of total unique elements seen

	int* unique_values = (int*) malloc(max_size * sizeof(int));	// Allocate for every element in multidimensional array, in case they are all unique
	
	for(int i = 0; i < num_arrays; i++){				// Loop to the number of arrays in multidimensional array
		
		for(int j = 0; j < sizes[i]; j++){			// Loop to the size in each individual array
			if (!contains_element(values[i][j], unique_count, unique_values)){	// If the unique array does not contain an element in an individual array
			unique_values[unique_count] = values[i][j];			// Add it to the unique array
			unique_count++;                                                 // And increment the count
			}
		
		}
	
	}

	int* merged_elements = (int*) malloc((unique_count + 1) * sizeof(int)); // Allocate the number of unique elements plus one for the array to be returned
									      // The extra space is for the number of elements inside the array
	merged_elements[0] = unique_count;		// Add the size to start of array

	for(int i = 1; i <= unique_count; i++) {	// From the second element to the number of unique elements, add the unique elements to the new array
	merged_elements[i] = unique_values[i - 1];
	}

	mergesortRange(merged_elements, 1, unique_count + 1);	// Sort the elements in the new array
	free(unique_values);	
	
	return merged_elements;
}
