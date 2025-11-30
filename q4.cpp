#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

bool isPalindrome(Node* head) {
    if(!head) return true;

    Node *L = head, *R = head;

    // go to last
    while(R->next) R = R->next;

    // compare both ends
    while(L != R && R->next != L) {
        if(L->data != R->data) return false;
        L = L->next;
        R = R->prev;
    }
    return true;
}
