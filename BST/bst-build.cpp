#include <bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    //base case
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //Insert in Right part
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //Insert in Left Part
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void lvlOrderTrsl(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* topNode = q.front();
        q.pop();

        if(topNode==NULL){
            //purana level complete traverse ho chuka hai 
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            //traversing at a level
            cout<<topNode->data<<" ";
            if(topNode->left){
                q.push(topNode->left);
            }
            if(topNode->right){
                q.push(topNode->right);
            }
        }
      
    }
}

int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    lvlOrderTrsl(root);
   

    return 0;
}