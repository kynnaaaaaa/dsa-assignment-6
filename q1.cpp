#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

// Insert at end
void insert(int x) {
    Node* t = new Node{x, NULL, NULL};
    if(head == NULL) head = t;
    else {
        Node* p = head;
        while(p->next) p = p->next;
        p->next = t;
        t->prev = p;
    }
}

// Delete a node with value x
void deleteNode(int x) {
    Node* p = head;
    while(p && p->data != x) p = p->next;
    if(!p) return;

    if(p->prev) p->prev->next = p->next;
    else head = p->next;

    if(p->next) p->next->prev = p->prev;

    delete p;
}

// Search a value
bool searchNode(int x) {
    Node* p = head;
    while(p) {
        if(p->data == x) return true;
        p = p->next;
    }
    return false;
}

// Print list
void display() {
    Node* p = head;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    deleteNode(20);

    cout << "Search 30: " << (searchNode(30) ? "Found" : "Not Found") << "\n";

    display();
}
