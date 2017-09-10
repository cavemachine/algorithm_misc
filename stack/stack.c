#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *top;
struct node *oldtop;

void push(int v);
void pop();
void show_stack();

void push(int v) {
    oldtop = malloc(sizeof(*oldtop));
    oldtop = top;
    top = malloc(sizeof(*top));
    top->value = v;
    top->next = oldtop;
}

void pop() {
    top = top->next;  
}

void show_stack() {
    struct node *intr = malloc(sizeof(*intr));
    intr = top;
    while (intr->next != 0) {
	printf("%i", intr->value);
	intr = intr->next;
    }
    free(intr);

}


int main() {
    top = malloc(sizeof(*top)); // C++ new equivalent
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    show_stack();
    
}
