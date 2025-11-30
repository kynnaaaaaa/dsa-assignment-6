#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at end (simple)
void insert(char x) {
    Node* t = new Node;
    t->data = x;
    t->prev = t->next = NULL;

    if (head == NULL) {
        head = t;
    } else {
        Node* p = head;
        while (p->next != NULL) p = p->next;
        p->next = t;
        t->prev = p;
    }
}

// Check palindrome
bool isPalindrome() {
    if (head == NULL) return true;

    Node* left = head;
    Node* right = head;

    // Move right to the end
    while (right->next != NULL) right = right->next;

    // Compare
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    insert('R');
    insert('A');
    insert('D');
    insert('A');
    insert('R');

    cout << (isPalindrome() ? "Palindrome" : "Not Palindrome");

    return 0;
}
