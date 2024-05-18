#include<iostream>
#include<stdlib.h>


using namespace std;


struct Node{
    int data;
    struct Node* next;
}*top = NULL;

void push(int data){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}

void print(){
    struct Node* temp;
    temp = top;

    while(temp){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int choice, data;
    while(1){
        cout<<"1. Push"<<endl;
        cout<<"2. Print"<<endl;
        cout<<"3. Quit"<<endl;

        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            cout<<"Enter the element to push: ";
            cin>>data;
            push(data);
            break;
        case 2:
            print();
            break;
        case 3:
            exit(1);
        default:
            cout<<"Wrong Choice"<<endl;
            break;
        }
    }
    return 0;
}
