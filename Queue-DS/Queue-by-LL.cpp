#include <bits/stdc++.h>
using namespace std;
/* Linked list implementation of Queue */

class node{
public:
    int data;
    node* next;

    node(int _data){
        data=_data;
        next=NULL;
    }
};

class Queue{

    node* front;
    node* back;

public:
    Queue(){
        front=NULL;
        back=NULL;
    }

    void push(int x){
        node* newNode = new node(x);
        if(front==NULL){
            back=newNode;
            front=newNode;
            return;
        }
        back->next = newNode;
        back=newNode;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;

        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"No element in the queue"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
};


int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

   
    while(!q.empty()){
        cout<<q.peek()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<q.peek()<<endl;
    q.pop();


    return 0;
}