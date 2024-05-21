#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 100

using namespace std;

char infix[MAX], postfix[MAX],stack_arr[MAX];
int top = -1;


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


void push(char data){
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


int space(char c){
    if(c==' '||c=='\t'){
        return 1;
    }
    else{
        return 0;
    }
}


int precedence(char symbol){
    switch(symbol){
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;

    }
}


void inf_to_postf()
{
    int i,j=0;
    char symbol, next;

    for(i=0;i<strlen(infix);++i){
        symbol = infix[i];
        if(!space(symbol))
        {
            switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '(')
                {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack_arr[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}


void print(){
    int i=0;
    for(i=0;i<strlen(postfix);++i){
        cout<<postfix[i];
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter Your Infix Expression: ";
    gets(infix);

    inf_to_postf();
    print();

    return 0;
}
