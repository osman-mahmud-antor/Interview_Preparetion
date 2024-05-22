#include<iostream>
#define MAX 10

using namespace std;

int Front=-1,rear=-1;

int q[MAX];

void Enqueue()
{
    int data;
    if(rear==MAX-1){
        cout<<"Overflow"<<endl;
    }
    else{
        if(Front==-1){
            Front = 0;
        }
        cout<<"Enter Your Element: ";
        cin>>data;
        rear++;
        q[rear] = data;
    }
}

void Dequeue()
{
    if(Front==-1 || Front>rear){
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<"Dequeued: "<<q[Front]<<endl;
        Front++;
    }
}

void Display()
{
    if(Front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        for(int i=Front;i<=rear;++i){
            cout<<q[i]<<"->";
        }
        cout<<endl;
    }
}


int main()
{
    cout<<"1. Enqueue/Insert"<<endl;
    cout<<"2. Dequeue/Delete"<<endl;
    cout<<"3. Display Elements"<<endl;
    cout<<"4. Exit"<<endl;
    int choice;
    while(1){
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }


}
