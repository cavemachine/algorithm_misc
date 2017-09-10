#include <stdlib.h>
#include <stdio.h>

void push(int v);
void pop();
void show_stack();

int stack[4];
int stack_ptr;

void push(int v){
    if (stack_ptr < 4) {
    stack[stack_ptr] = v;
    ++stack_ptr;
    } else {
	printf(" Stack is full");
    }
}

void pop() {
    --stack_ptr; 
    stack[stack_ptr] = (int) NULL;
    
}

void show_stack() {
    int i = 0;
    while (stack[i] != (int) NULL) {
	printf("%i", stack[i]);
	++i;
    }
}

int main() {
    stack_ptr = 0;
    push(7);
    push(8);
    push(9);
    push(3);
    push(2);
    show_stack();
    
}
