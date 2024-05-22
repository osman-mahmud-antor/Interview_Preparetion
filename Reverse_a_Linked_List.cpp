struct Node* reverse_Linked_List(struct Node* head){
    struct Node* current = head;
    struct Node* previous = NULL;
    struct Node* next = NULL;

    while(current != NULL){
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    return previous;
}
