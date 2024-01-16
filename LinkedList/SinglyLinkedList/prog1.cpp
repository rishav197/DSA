#include <bits/stdc++.h>
using namespace std;
/*
1. insertAtTail / insertAtHead
2. print --prt()
3. search--srch()
4. reverse() --Iterative approach
5. reverseRecursive() --Recursive approach
*/

class node{ //node class
    public:
    int data;
    node* next;

    node(int val){ //constructor
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){ head=n; return; }
    
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }


    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }

    node* todelete = temp->next;  // temp is prev node of the deleting node
    temp->next = temp->next->next; // link bw prev node and node next to deleted node
    delete todelete;
}

void prt(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool srch(node* head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

node* reverse(node* &head){
    node* preptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;

        currptr->next=preptr;
        preptr=currptr;
        currptr=nextptr;
    }
    return preptr; //preptr is the head of reversed linkedlist
} 

node*   reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    prt(head);


    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,-2);
    prt(head);
    node* newHead = reverse(head);
    prt(newHead);


    return 0;
}