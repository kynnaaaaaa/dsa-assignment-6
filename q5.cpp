bool isCircular(Node* head) {
    if(head == NULL) return false;

    Node* p = head->next;

    while(p != NULL && p != head)
        p = p->next;

    return (p == head);
}
