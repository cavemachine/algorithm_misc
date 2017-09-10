
#include <stdio.h>
#include <stdlib.h>

int size_array = 1;
int *array;
int first = 0;
int last = 0;
int items = 0;

void enqueue(int var) {
    if (last < size_array) {
	array[last] = var;

    } else {
	size_array = size_array * 2;
	int *oldarray = array;
	int *newarray =  (int *) malloc(sizeof(int)*size_array);
	for (int j = first; j < last; j++) {
	    newarray[j] = array[j];
	}
	array = newarray;
	free(oldarray);
	first = 0;
	last = 0;
	array[last] = var;
    }
    ++last;
    ++items;
}

void dequeue() {
    first = first  + 1;
    --items;
    if ((last - first) < (int)(sizeof(array)/sizeof(int))/4) {
	int *oldarray;
	oldarray = array;
	int *newarray = malloc(sizeof(array)/2);
	int k = 0;
	for (int j = first; j < last; ++j) {
	    newarray[k] = array[j];
	    ++k;
	}
	array = newarray;
	last = last - first;
	first = 0;
	free(oldarray);
    }

}

int main() {
    array = (int *) calloc(size_array,sizeof(int));
    
    int i = 0;
    while (i < 60000000) {
     	enqueue(2);
    	i++;
    }
    while (i > 0) {
	dequeue();
	--i;
    }

    printf("OK!\n");
    printf("%i items\n\n", items);

}
