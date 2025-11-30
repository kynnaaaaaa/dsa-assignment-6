1) int sizeDLL(Node* head) {
    int c = 0;
    while(head) {
        c++;
        head = head->next;
    }
    return c;
}
2)int sizeCLL(Node* head) {
    if(!head) return 0;
    int c = 0;
    Node* p = head;
    do {
        c++;
        p = p->next;
    } while(p != head);
    return c;
}
