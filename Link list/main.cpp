/**
 * @file main.cpp
 * @author nguyenanhdo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};


void init(Node *&head);
void addFirst(Node *&head, int value);
void printNode(Node *head);
void addLast(Node *&head, int value);
void addAfter(Node *head, int v, int value);
void deleteFirst(Node *&head);
void deleteLast(Node *head);

int main() {

    Node *head;
    init(head);

    addFirst(head, 100);
    addLast(head, 200);
    addAfter(head, 200, 55);
    
    // deleteLast(head);

    printNode(head);
    

    return 0;
}

void init(Node *&head) {

    head = NULL;
}

Node* createNode(int value) {

    Node *p = new Node;
    p->value = value;
    p->next = NULL;
    return p;
}

void addFirst(Node *&head, int value) {

    Node *p = createNode(value);
    p->next = head;

    // Cập nhật lại head
    head = p;
}

void addLast(Node *&head, int value) {

    Node *p = createNode(value);
    if(head != NULL) { // Để tránh lỗi NullPointer
        // Xác định node cuối cùng
        // Kết thúc vòng lặp, last là node cuối cùng
        Node *last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    } else {
        head = p;
    }
}

void printNode(Node *head) {

    Node *p = head;
    while(p != NULL) {
        cout << p->value << "\t";
        p = p->next;
    }
}

// Thêm node sau một node
void addAfter(Node *head, int v, int value) {

    Node *p = createNode(value);

    // Tìm node có giá trị là v
    Node *q = head;
    while(q != NULL && q->value != v) { // q != NULL => tránh lỗi NullPointer
        q = q->next;
    }

    if (q != NULL) {
        // Để tránh mất dấu của node sau q
        p->next = q->next;
        q->next = p;
    }
}

void deleteFirst(Node *&head) {

    if (head != NULL) {
        Node *p = head;
        head = p->next;
        p->next = NULL;
        delete p;
    }
}

void deleteLast(Node *&head) {

    // Xác định nút cuối cùng và nút gần cuối   
    if (head != NULL) {
        Node *last = head;
        Node *prev = NULL;

        while (last->next != NULL) {
            prev = last;
            last = last->next;
        }
        if (prev == NULL) { // Danh sách có một phần tử
            deleteFirst(head);
        } else {
            prev->next = NULL;
            delete last;
        }
    }
}