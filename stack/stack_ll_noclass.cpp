#include <iostream>
#include <stdlib.h>

using namespace std;
void push(string str_x);
void pop();
void show_stack();

struct node {
    string node_str;
    node *next;
};

node *top;
node *oldtop;

void push(string str_x) {
    //   oldtop = new node();
    oldtop = top;
    top = new node();
    top->node_str = str_x;
    top->next = oldtop;
}
void pop() {
    top = top->next;  
}

void show_stack() {
    node *intr;
    intr = top;
    while (intr->next != 0) {
	cout << intr->node_str;
	intr = intr->next;
    }
    cout << intr->node_str;
}

int main() {
    top = new node();
    top->node_str = "first";
    top->next = NULL;
    
    push("aaa");
    push("bbb");
    push("ccc");
    push("ddd");
    show_stack();
    
}
