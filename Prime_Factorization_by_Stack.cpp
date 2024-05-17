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

void prime_Fact(int value)
{
    int i = 2;
    while(value!=1){
        while(value%i==0){
            push(i);
            value = value/i;
        }
        i++;
    }
    while(top!=-1){
        cout<<pop()<<" ";
    }
    cout<<endl;
}

int main()
{
    int num;
    cout<<"Put Your Number: ";
    cin>>num;
    prime_Fact(num);
    return 0;
}
