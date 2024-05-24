Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(x==1){
        return head->next;
    }
    else{
        Node* current = head;
        for(int i=2;i<x;++i){
            current = current->next;
        }
        current->next = current->next->next;

        return head;
    }
}
