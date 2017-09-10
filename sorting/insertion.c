#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array_size;

void insertion_sort(int *array) {
    int tmp;
    for (int pos_left = 0; pos_left < array_size - 1; pos_left++) {
	for (int pos_right = pos_left + 1; pos_right > -1; pos_right--) {
	    if (array[pos_right] < array[pos_right-1]) {
		tmp = array[pos_right-1];
		array[pos_right-1] = array[pos_right];
		array[pos_right] = tmp;
	    } else {
		break;
	    }
	}
    }
    
}

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
    	printf("Missing array size argument! Exiting.\n");
    	return 0;
    };
    array_size = strtol(argv[1],NULL,10);
    
    srand(time(NULL));
    clock_t t;
    double time_taken;
    int w;

    printf("Allocating memory... ");
    t = clock();
    int *rand_array = (int*) malloc(sizeof(int)*array_size);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("[%f secs]\n", time_taken);
    
    printf("Inserting random numbers on array... ");
    t = clock();
    for (int i = 0; i < array_size; ++i) {
    	w = (rand() % 10) + 1;
    	rand_array[i] = w;
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("[%f secs]\n", time_taken);
    
    printf("Sorting array using insertion sort...  ");
    fflush(stdout);
    t = clock();
    insertion_sort(rand_array);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf(" [%f secs]\n", time_taken);

    printf("Done! \n");
    free(rand_array);
    return 0;

}
