#include <bits/stdc++.h>
using namespace std;
/**/

//creating node [data|link]
class node{
    public:
    int data;
    node* next;

    node(int val){ //constructor
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val); //creating new node
    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head; //temporary pointer to iterate over the linkedlist
    while(temp->next!=NULL){
        temp = temp->next;
    }
    //we reach at last node 
    temp->next = n; //linking last node with the new node[by pointing next of last node to newNode]
}

void insertAtFront(node* &head, int val){
    
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);

    display(head);

    return 0;
}