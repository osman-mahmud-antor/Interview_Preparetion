#include<iostream>

using namespace std;


struct Node {
    int data;
    struct Node* next;
};

struct Node* Reverse_List(struct Node* head)
{
    struct Node* previous = NULL;
    struct Node* forward_value = NULL;

    while(head != NULL){
        forward_value = head->next;
        head->next = previous;
        previous = head;
        head = forward_value;
    }
    head = previous;

    return head;
}

struct Node* Del_Whole_List(struct Node* head){
    struct Node* temp;
    temp = head;

    while(temp!=NULL){
        temp=temp->next;
        free(head);
        head = temp;
    }
    return head;
}


void delete_at_position(struct Node **head, int posi)
{
    struct Node* current = *head;
    struct Node* previous = *head;

    if(*head==NULL){
        cout<<"Already Kicchu nai"<<endl;
    }
    else if(posi==1){
        *head = current->next;
        free(current);
        current = NULL;
    }
    else{
        while(posi!=1){
            previous = current;
            current = current->next;
            posi--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}


void print_data(struct Node *head)
{
    if(head==NULL){
        cout<<"Kicchu nai"<<endl;
    }
    else{
        struct Node *ptr = NULL;
        ptr = head;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
        cout<<"NULL"<<endl;
    }
}

int main()
{
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 20;
    head->next = NULL;

    struct Node* current = NULL;
    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 16;
    current->next = NULL;

    head->next = current;


    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 9;
    current->next = NULL;


    head->next->next = current;


    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 3;
    current->next = NULL;


    head->next->next->next = current;

    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 6;
    current->next = NULL;


    head->next->next->next->next = current;

    print_data(head);

    head = Reverse_List(head);
    print_data(head);


    int position = 3;

    delete_at_position(&head, position);


    print_data(head);

    head = Del_Whole_List(head);

    print_data(head);


    return 0;

}
