#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<string>

#define MAX 100
using namespace std;

class Stack{

    private:
    string item[MAX];
    int top;

    public:
    Stack(){

        top = -1;
    }

    bool isEmpty(){
        return top ==-1;
    }

    bool isFull(){
        return top == MAX -1;
    }

    void push(string value){
        if(isFull()){
            cout<<"Stack is full cant push "<< value<< endl;
        }
        else{
            item[++top]=value;

        }
    }

    string pop (){
        if(isEmpty()){
            cout<<"Stack is empty cant pop";
           
        }

        else{
           return item[top--] ;
        }
    }
    string peek(){
        if (isEmpty()){
            cout<<"nothing in stack"<<endl;
        }
        else{
           return item[top];
        }
    }

    void clear(){
        top=-1;
    }
};


#endif