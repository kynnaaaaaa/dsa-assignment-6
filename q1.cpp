#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node* head = 0;

// Insert at end
void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->prev = 0;
    t->next = 0;

    if(head == 0) {
        head = t;
        return;
    }

    Node* p = head;
    while(p->next != 0)
        p = p->next;

    p->next = t;
    t->prev = p;
}

// Delete a value
void deleteNode(int x) {
    Node* p = head;

    while(p != 0 && p->data != x)
        p = p->next;

    if(p == 0) return;

    if(p->prev != 0)
        p->prev->next = p->next;
    else
        head = p->next;

    if(p->next != 0)
        p->next->prev = p->prev;

    delete p;
}

// Search a value
bool searchNode(int x) {
    Node* p = head;
    while(p != 0) {
        if(p->data == x) return true;
        p = p->next;
    }
    return false;
}

// Display DLL
void display() {
    Node* p = head;
    while(p != 0) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    deleteNode(20);

    cout << "Search 30: " << (searchNode(30) ? "Found" : "Not Found") << endl;

    display();
}
