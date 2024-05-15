#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node* link;
};

struct Node* add_at_begining(struct Node* head, int beginVal){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->data = beginVal;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}


void add_at_end(struct Node* head, int newVal)
{
    struct Node *ptr, *temp;
    ptr = head;

    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = newVal;
    temp->link = NULL;

    while(ptr->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void add_at_position(struct Node* head, int data, int pos)
{
    struct Node* ptr = head;
    struct Node* ptr2 = (struct Node*)malloc(sizeof(struct Node));

    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos!=1){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;

}

struct Node* Del_at_first_item(struct Node* head){
    if(head==NULL){
        cout<<"Empty"<<endl;
    }
    else{
        struct Node* temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }

    return head;
}

struct Node* Del_at_last_item(struct Node* head){
    if(head==NULL){
        cout<<"kicchu nai"<<endl;
    }
    else if(head->link==NULL){
        free(head);
        head = NULL;
    }
    else{
        struct Node *temp = head;
        struct Node *temp2 = head;

        while(temp->link != NULL){
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }

    return head;
}



void print_data(struct Node* head)
{
    if(head==NULL)
        cout<<"Linked list is empty.";

    struct Node* ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->link;
    }cout<<"NULL"<<endl;
}



int main()
{
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 41;
    head->link = NULL;

    struct Node* current = NULL;
    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 25;
    current->link = NULL;
    head->link = current;

    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 16;
    current->link = NULL;
    head->link->link = current;

    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 12;
    current->link = NULL;
    head->link->link->link = current;

    print_data(head);

    add_at_end(head, 10);

    print_data(head);

    int beginVal = 6;

    head = add_at_begining(head, beginVal);

    print_data(head);

    int newData = 21, position = 3;

    add_at_position(head,newData,position);

    print_data(head);

    head = Del_at_first_item(head);

    print_data(head);

    head = Del_at_last_item(head);

    print_data(head);

    return 0;
}
