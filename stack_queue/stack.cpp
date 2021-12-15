#include <iostream>
#define MAX 10

using namespace std;

struct Stack {
    int a[MAX];
    int top;
};

void init(Stack &stack);
void push(Stack &s, int x);
int pop(Stack &s);

int main() {

    Stack s;
    
    init(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);

    return 0;
}


void init(Stack &stack) {
    stack.top = -1;
}


void push(Stack &s, int x) {
    s.top += 1;
    s.a[top] = x;
}


int pop(Stack &s) {
    
    return s.a[s.top--];
}


bool isEmpty(Stack s) {
    return s.top < 0;
}


bool isFull(Stack s) {
    return s.top == MAX - 1;
}
