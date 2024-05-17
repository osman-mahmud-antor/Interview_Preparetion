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

void Dec2Bin(int decimal)
{
    while(decimal!=0){
        push(decimal%2);
        decimal = decimal/2;
    }
}


void print(){
    int i;
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    while(!isEmpty()){
        cout<<pop();
    }
    cout<<endl;
}


int main()
{
    int num;
    cout<<"Put Your Decimal Number: ";
    cin>>num;
    Dec2Bin(num);
    print();
    return 0;
}
