#include <stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"


int total_elements(int num_arrays, int* sizes) {
        int total_elements = 0;

        for(int i = 0; i < num_arrays; i++) {
        total_elements += sizes[i];
        }
	return total_elements;
}

bool contains_element(int element, int size, int* array) {
        bool contains = false;

        for (int i = 0; i < size; i++){

                if (array[i] == element){
                contains = true;
                }
        }
        return contains;
}



int* array_merge(int num_arrays, int* sizes, int** values) { 
	int max_size = total_elements(num_arrays,sizes);
	int unique_count = 0;

	int* unique_values = (int*) malloc(max_size * sizeof(int));
	
	for(int i = 0; i < num_arrays; i++){
		
		for(int j = 0; j < sizes[i]; j++){
			if (!contains_element(values[i][j], max_size, unique_values)){
			unique_values[unique_count] = values[i][j];
			unique_count++;
			}
		
		}
	
	}

	int* merged_elements = (int*) malloc(unique_count + 1 * sizeof(int));

	merged_elements[0] = unique_count;

	for(int i = 1; i < unique_count; i++) {
	merged_elements[i] = unique_values[i - 1];
	}

	mergesortRange(merged_elements, 1, unique_count + 1);
	
	return merged_elements;
}
