#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
using namespace std;

template <class T>
class MyStack{
private:
    struct StackNode{
        T value;
        StackNode *next;
    };

    StackNode *top;
public:
    MyStack()
        {top = nullptr;}

    ~MyStack(){
        StackNode *nodeptr = nullptr, *nextnode = nullptr;
        nodeptr = top;
        while(nodeptr != nullptr){
            nextnode = nodeptr->next;
            delete nodeptr;
            nodeptr = nextnode;
        }
    }

    void push(T val){
        StackNode *newnode = nullptr;
        newnode = new StackNode;
        newnode->value = val;
        if(isEmpty()){
            top = newnode;
            newnode->next = nullptr;
        }else{
            newnode->next = top;
            top = newnode;
        }
    }

    void pop(T &val){
        StackNode *temp = nullptr;
        if(isEmpty()){
            cout << "The stack is empty.\n";
        }else{
            val = top->value;
            temp = top->next;
            delete top;
            top = temp;
        }
    }

    bool isEmpty(){
        bool status;
        if(!top){
            status = true;
        }else{
            status = false;
        }
        return status;
    }

    void print(){
      StackNode *nodeptr;
      nodeptr = top;
      while(nodeptr != nullptr){
        cout << nodeptr->value << "  ";
        nodeptr = nodeptr->next;
    }cout<<endl;}

};

#endif

