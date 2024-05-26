#include <bits/stdc++.h>
using namespace std;
/* Doubly Linked List */
/* Head->1=2=3=4=5->NULL */

class node{
    public: // variable data, ptrs are public
    int data;
    node* prev;
    node* next;

    node(int val){ //constructor
        data=val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){ //when atleast one node insert to dbly ll
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head=head->next; //current new head
    head->prev=NULL;

    delete todelete;
}

void deletion(node* &head, int pos){ //pos--position
    if(pos<1){ return; }
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next; //pichhale mai agle dal rhe hai
    if(temp->next!=NULL){
        temp->next->prev=temp->prev; //agle mai pichhla dal rhe hai
    }
    delete temp;
}

int main(){

    node* h = NULL;
    insertAtTail(h,1);
    insertAtTail(h,2);
    insertAtTail(h,3);
    insertAtTail(h,4);
    insertAtTail(h,5);
    insertAtTail(h,-6);
    
    display(h);
    // insertAtHead(h,-1);
    // insertAtHead(h,-2);
    // insertAtHead(h,-3);

    /* Deletion deletion(head, position)*/
    deletion(h,6);
    display(h);
    // deletion(h,2);
    // display(h);
    // deletion(h,3);
    // display(h);
    // deletion(h,1);
    // display(h);
    // deletion(h,2);
    // display(h);

    return 0;
}