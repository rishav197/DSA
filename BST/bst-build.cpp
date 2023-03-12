#include <bits/stdc++.h>
using namespace std;
/*Build a BST */

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data){
        data=_data;
        left=NULL;
        right=NULL;
    }
};


Node* insertBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insertBST(root->left, val);
    }
    else{ //val>root->data
        root->right = insertBST(root->right, val);
    }

    return root;
}

void inOrderprt(Node* root){
    if(root==NULL){
        return;
    }

    inOrderprt(root->left);
    cout<<root->data<<" ";
    inOrderprt(root->right);

}

int main(){

    // Node* root = NULL;
    // root = insertBST(root,5);
    // insertBST(root,1);
    // insertBST(root,3);
    // insertBST(root,4);
    // insertBST(root,2);
    // insertBST(root,7);



    return 0;
}