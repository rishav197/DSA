#include <bits/stdc++.h>
using namespace std;

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

int search(int inOrder[], int val, int st, int ed){
    for(int i=st; i<=ed; ++i){
        if(inOrder[i]==val){
            return i;
        }
    }
    return -1;
}


Node* buildTree(int preOrder[],int inOrder[],int st,int ed){
    static int idx=0;
    if(st>ed){
        return NULL;
    }
    int val = preOrder[idx];
    idx++;
    Node* root = new Node(val);
    if(st==ed){
        return root;
    }

    int pos = search(inOrder,val,st,ed);
    root->left = buildTree(preOrder,inOrder,st,pos-1);
    root->right = buildTree(preOrder,inOrder,pos+1,ed);

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

    // int preOrder[] = {1,2,4,3,5};
    // int inOrder[] = {4,2,1,5,3};


    int preOrder[] = {1,2,4,5,3,6,7};
    int inOrder[] = {4,2,5,1,6,3,7};

    Node* root = buildTree(preOrder,inOrder,0,6);
    inOrderprt(root); // Print of the Build Tree 

    return 0;
}