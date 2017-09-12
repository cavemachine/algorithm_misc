
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array_size;

void shell_sort(int *array) {
    int key_elements[30];
    int last_key_element;
    int res = 1;
    int prev_res = 1;
    
    for (int i = 0; prev_res < array_size; i++) {
	prev_res = res;	
	key_elements[i] = prev_res;
	last_key_element = i;
	res = res*3 + 1;
    }
    int right;
    int left;
    int tmp;
    int pos_right;
    last_key_element--;
    
    for (int key = last_key_element; key > -1; key--) {
	for (int pos_left = 0; pos_left + key_elements[key] < array_size; pos_left++) {
	    pos_right = pos_left + key_elements[key];

	    right = pos_right;
	    left = pos_left;
	    
	    while (array[right] < array[left]) {
		tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		right = right - key_elements[key];
		left = left - key_elements[key];
		if (left < 0) {
		    break;
		}
	    }

	}
    }
}



int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
    	printf("Missing array size argument!\n");
	//	return 0;
	array_size = 10000;
    } else {
	array_size = strtol(argv[1],NULL,10);	
    }

    
    srand(time(NULL));
    clock_t t;
    double time_taken;

    printf("Allocating memory... ");
    t = clock();
    int *rand_array = (int*) malloc(sizeof(int)*array_size);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("[%f secs]\n", time_taken);
    
    printf("Inserting random numbers on array...");
    t = clock();
    for (int i = 0; i < array_size; ++i) {
    	rand_array[i] = (rand() % 10) + 1;
//	printf("%i ", rand_array[i]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("[%f secs]\n", time_taken);
    
    printf("Sorting array using SHELL sort...  ");
    fflush(stdout);
    t = clock();
    shell_sort(rand_array);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf(" [%f secs]\n", time_taken);

    /* for (int i = 0; i < array_size; ++i) { */
    /* 	printf("%i ", rand_array[i]); */
    /* } */
    printf("Done! \n");
    free(rand_array);
    return 0;

}
