#include <iostream>
#include <string>
using namespace std;

//----linked list stack implementation----//

class Stack_String {  
public:
    Stack_String() {
	top = NULL;
    }
    ~Stack_String() {
	delete top;
    }
    void push(string &str_push);
    void pop();
    void show_stack();

private:    
    struct node {
	string node_string;
	node *next;
    }; 
    node *top;
};

//-----------------------------------------------

void Stack_String::push(string &str_push) {
    node *oldTop;
    oldTop = top;
    top = new node();
    top->node_string = str_push;
    top->next = oldTop;
}


void Stack_String::pop() {
    node *tmpnode;
    tmpnode = top;
    top = top->next;
    delete tmpnode;
  }

void Stack_String::show_stack(){
    node *interato;
    interato = top;
    while (interato->next != NULL) {
	cout << interato->node_string;
	interato = interato->next;
    }
    cout << interato->node_string;    
}


int main() {
    Stack_String *stack = new Stack_String();    

    string wod;
    wod = "bbb";
    stack->push(wod);
    wod = "ccc";
    stack->push(wod);
    wod = "ddd";
    stack->push(wod);
    wod = "eee";
    stack->push(wod);
    wod = "fff";
    stack->push(wod);
    stack->pop();
    stack->show_stack();

    delete stack;

  }

