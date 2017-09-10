
#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;


void enqueue(int val) {
    struct node *newlast;
    newlast = malloc(sizeof(struct node));
    newlast->item = val;
    newlast->next = NULL;
    last->next = newlast;
    last = newlast;
    if (!first) {
	first = last;
    }
}
    
void dequeue() {
    struct node *tmpfirst;
    tmpfirst = first;
    first = first->next;
    free(tmpfirst);
   
}
    
int main() {
   last = malloc(sizeof(struct node));
    int i = 0;
    while (i < 6000000) {
   	enqueue(2);
   	i++;
    }
 

}
