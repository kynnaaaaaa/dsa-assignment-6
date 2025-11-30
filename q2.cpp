#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *n1 = new Node{20, NULL};
    Node *n2 = new Node{100, NULL};
    Node *n3 = new Node{40, NULL};
    Node *n4 = new Node{80, NULL};
    Node *n5 = new Node{60, NULL};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1; // circular

    Node* head = n1;
    Node* p = head;

    do {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);

    cout << head->data; // repeat
}
