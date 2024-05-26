#include <bits/stdc++.h>
using namespace std;
/* Queue array based implementaion */
#define n 10

class Queue{
    int* arr;
    int front;
    int back;

public:
    Queue(){
        arr = new int[n];
        front=-1;
        back=-1;
    }

    void enqueue(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front==-1 || front>back){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            // cout<<"No Element in Queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
        return false;
    }
};


int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(2);
    q.enqueue(3);   
    q.enqueue(4);
    
    // while(!q.empty()){
    //     cout<<q.peek()<<endl;
    //     q.dequeue();
    // }

    // cout<<q.empty()<<endl;
    // cout<<q.peek()<<endl;
    // q.dequeue();

    for(int i=1; i<=11; ++i){
        q.enqueue(i);
    }

    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.dequeue();
    }


    return 0;
}