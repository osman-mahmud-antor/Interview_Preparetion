#include<iostream>
#include<stdlib.h>
#define MAX 10


using namespace std;

int top = -1;
int stack_arr[MAX];

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

int pop(){
    if(isEmpty()){
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    int value;
    value = stack_arr[top];
    top = top-1;
    return value;
}

int peek(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    return stack_arr[top];
}

void print(){
    int i;
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    for(i=top;i>=0;i--){
        cout<<stack_arr[i]<<" ";
    }
    cout<<endl;
}

void push(int data){
    if(isFull()){
        cout<<"STACK OVERFLOW"<<endl;
        return;
    }
    else{
        top = top+1;
        stack_arr[top] = data;
    }
}

int main(){
    int choice, data;
    while(1){
        cout<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Print the top element"<<endl;
        cout<<"4. Print all the elements of the stack"<<endl;
        cout<<"5. Quit"<<endl;
        cout<<"Please Enter Your Choice: ";
        cin>>choice;


        switch(choice){
        case 1:
            cout<<"Enter the element you want to push:";
            cin>>data;
            push(data);
            break;
        case 2:
            data = pop();
            cout<<"The deleted item is: "<<data<<endl;
            break;
        case 3:
            cout<<"The top-most element is: "<<peek()<<endl;
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Wrong Choice!"<<endl;
        }
    }
    return 0;
}
