#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Make a simple linked list (not circular)
void insert(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    if (head == NULL) head = t;
    else {
        Node* p = head;
        while (p->next != NULL) p = p->next;
        p->next = t;
    }
}

// Check if circular
bool isCircular() {
    if (head == NULL) return false;

    Node* p = head->next;

    while (p != NULL && p != head)
        p = p->next;

    return (p == head);
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    // Uncomment this to make it circular
    // Node* p = head;
    // while (p->next != NULL) p = p->next;
    // p->next = head;

    cout << (isCircular() ? "Circular" : "Not Circular");

    return 0;
}
