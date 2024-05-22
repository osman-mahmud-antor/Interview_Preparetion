#include<iostream>
using namespace std;


struct Node {
	int data;
	Node* next;
};

struct Node* Front = NULL;
struct Node* Rear = NULL;

void Linked_List_Travarsal(struct Node* ptr){
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}


void Enqueue(int value){
    struct Node* newElement = (struct Node*)malloc(sizeof(struct Node));

    if(newElement==NULL){
        cout<<"Queue is Full"<<endl;
    }
    else{
        newElement->data = value;
        newElement->next = NULL;

        if(Front==NULL){
            Front=Rear = newElement;
        }
        else{
            Rear->next = newElement;
            Rear = newElement;
        }
    }
}

int Dequeue(){
    int value = -1;
    struct Node* temp;

    if(Front==NULL){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        temp = Front;
        Front = Front->next;
        value = temp->data;
        free(temp);
    }
    return value;
}



int main()
{
    Enqueue(20);
    Enqueue(16);
    Enqueue(9);
    Enqueue(3);

    Linked_List_Travarsal(Front);

    int dequeElement = Dequeue();

    cout<<dequeElement<<endl;

    Linked_List_Travarsal(Front);

    return 0;
}
