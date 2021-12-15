#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

struct CircularLinkedList {
    Node *head;
    Node *tail;
};

void init(CircularLinkedList &ls);

int main() {

    CircularLinkedList ls;
    init(ls);

    return 0;
}


void init(CircularLinkedList &ls) {
    
    ls.head = NULL;
    ls.tail = NULL;
}


Node* createNode(int value) {
 
    Node *p = new Node;
    p->value = value;
    p->next = NULL;
 
    return p;
}


void addFirst(CircularLinkedList &ls, int value) {

    Node *p = createNode(value);
}