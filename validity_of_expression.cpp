#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 100


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

int char_match(char a, char b){
    if(a=='(' && b==')'){
        return 1;
    }
    else if(a=='{' && b=='}'){
        return 1;
    }
    else if(a=='[' && b==']'){
        return 1;
    }
    else{
        return 0;
    }
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


char pop(){
    if(isEmpty()){
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    char value;
    value = stack_arr[top];
    top = top-1;
    return value;
}


int check_balance(char* s)
{
    char temp;
    int i;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(isEmpty()){
                cout<<"Right elements are more than the left"<<endl;
                return 0;
            }
            else{
                temp = pop();
                if(!char_match(temp, s[i])){
                    cout<<"Mismatched"<<endl;
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        return 1;
    }
    else{
        return 0;
    }
}





int main()
{
    char exp[MAX];
    cout<<"Enter the Algebric Expression: ";
    gets(exp);


    int balanced;
    balanced = check_balance(exp);

    if(balanced == 1){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}
