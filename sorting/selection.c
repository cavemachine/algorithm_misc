/* Usage example: "./selection 10000" to generate 10000 random numbers and sort them. No numbers are shown, just the time taken to process. The output will be like this:
   Allocating memory... [0.000008 secs]
   Inserting random numbers on array... [0.000346 secs]
   Sorting array using selection sort...  100% [0.079272 secs]
   Done! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array_size;

void selec_sort(int *array){
    int smaller;
    int five_percent = array_size/20;
    int five_percent_inc = 5;
    int tmp_pos;
    for (int pos_left = 0; pos_left < array_size-1; pos_left++) {
	smaller = pos_left+1;
	if (pos_left > five_percent) {
	    printf("%i%%", five_percent_inc);
	    fflush(stdout);
	    five_percent += array_size/20;
	    five_percent_inc += 5;
	    if (five_percent_inc == 10) {
		printf("\033[2D"); // moves the cursor 2 steps back
	    } else {
		printf("\033[3D");
	    }
	}
	    
	for (int pos_right = pos_left + 1 ; pos_right < array_size; pos_right++) {
	    if (array[pos_right] < array[smaller]) {
		smaller = pos_right;
	    }
	}
	if (array[pos_left] > array[smaller]) {
	    tmp_pos = array[pos_left];
	    array[pos_left] = array[smaller];
	    array[smaller] = tmp_pos;
	}
    }
    printf("100%%");
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
    
    printf("Sorting array using selection sort...  ");
    fflush(stdout);
    t = clock();
    selec_sort(rand_array);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf(" [%f secs]\n", time_taken);

    printf("Done! \n");
    free(rand_array);
    return 0;
}
