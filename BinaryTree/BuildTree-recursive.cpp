#include <bits/stdc++.h>
using namespace std;

/* BuildTree Recursively */
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


Node* buildTree(Node* root){
    int data;
    cout<<"Enter data:"<<endl;
    cin>>data;
    root = new Node(data);

    if(data==-1){
        return NULL;
    }


    cout<<"Enter the data for inserting in Left of "<<data<<endl;
    root->left=buildTree(root->left);


    cout<<"Enter the data for inserting in Right of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}


int main(){

    Node* root = NULL;

    buildTree(root);
   

    return 0;
}