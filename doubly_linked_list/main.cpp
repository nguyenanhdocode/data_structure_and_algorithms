#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

struct DoublyLinkedList {
    Node *head, *tail;
};

void init(DoublyLinkedList &ls);
void addFirst(DoublyLinkedList &ls, int value);
void addLast(DoublyLinkedList &ls, int value);
void printList(DoublyLinkedList ls);
void printRightToLeft(DoublyLinkedList ls);
void deleteFirst (DoublyLinkedList &ls);
void deleteLast(DoublyLinkedList &ls);
void addAfter(DoublyLinkedList &ls, int v, int value);

int main() {

    DoublyLinkedList ls;    
    init(ls);
   
    addLast(ls, 1);
    addLast(ls, 2);
    addLast(ls, 3);
    addLast(ls, 4);

    addAfter(ls, 4, 100);

    printList(ls);
    cout << endl;

    return 0;
}

void init(DoublyLinkedList &ls) {
    
    ls.head = NULL;
    ls.tail = NULL;
}


Node* createNode(int value) {
    
    Node *p = new Node;
    p->value = value;
    p->next = NULL;
    p->prev = NULL;

    return p;
}


void addFirst(DoublyLinkedList &ls, int value) {

    Node *p = createNode(value);
    if (ls.head == NULL) {
        ls.head = ls.tail = p;
    }
    else {
        p->next = ls.head;
        ls.head->prev = p;
        ls.head = p;
    }
}


void addLast(DoublyLinkedList &ls, int value) {

    Node *p = createNode(value);
    if (ls.head == NULL) {
        ls.head = ls.tail = p;
    }
    else {
        ls.tail->next = p;
        p->prev = ls.tail;
        ls.tail = p;
    }
}


void printList(DoublyLinkedList ls) {
    
    Node* p = ls.head;
    while (p != NULL) {
        cout << p->value << "\t";
        p = p->next;
    }
}


void printRightToLeft(DoublyLinkedList ls) {

    Node *p = ls.tail;

    while (p != NULL) {
        cout << p->value << "\t";
        p = p->prev;
    }
}


void deleteFirst (DoublyLinkedList &ls) {

    if (ls.head != NULL) {
        Node *p = ls.head;
        ls.head = p->next;
        p->next = NULL;
        delete p;
    }
}


void deleteLast(DoublyLinkedList &ls) {
    
    if (ls.head != NULL) {
        Node *p = ls.tail;

        if (p->prev != NULL) {
            p->prev->next = NULL;
            p->next = NULL;
        }
        else {
            deleteFirst(ls);
        }
    }
}


void addAfter(DoublyLinkedList &ls, int v, int value) {

    Node *q = ls.head;
    while (q != NULL && q->value != v) 
        q = q->next;
    
    if (q != NULL) {
        if (q->next == NULL) {
            addLast(ls, value);
        }
        else {
            Node *p = createNode(value);
            p->next = q->next;
            p->next->prev = p;
            q->next = p;
            p->prev = q;
        }
    }

}
