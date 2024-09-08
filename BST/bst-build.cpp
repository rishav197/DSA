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

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }

    return temp;
}


Node* deleteFromBST(Node* root, int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left!=NULL and root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL and root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL and root->right!=NULL){
            int min = minVal(root->right)->data;
            root->data=min;

            root->right = deleteFromBST(root->right, min);
            return root;
        }

    }
    else if(root->data>val){
        //left part mai jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        //right part mai jao
        root->right = deleteFromBST(root->right, val);
        return root;   
    }
}


int main(){

    // BST - 50 20 70 10 30 90 110 -1

    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    lvlOrderTrsl(root);
   
    //Deletion
    cout<<"After Deletion"<<endl;

    root = deleteFromBST(root, 50);
    cout<<"Printing the BST"<<endl;
    lvlOrderTrsl(root);


    return 0;
}