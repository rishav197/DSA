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

int srch(int inOrder[], int val, int st, int ed){
    for(int idx=st; idx<=ed; ++idx){
        if(inOrder[idx]==val){
            return idx;
        }
    }

    return -1;
}


Node* buildTree(int preOrder[],int inOrder[],int st,int ed){
    static int idx=0;
    if(st>ed){
        return NULL;
    }
    int curr = preOrder[idx];
    idx++;
    Node* root = new Node(curr);
    if(st==ed){
        return root;
    }


    int pos = srch(inOrder,curr,st,ed);
    root->left = buildTree(preOrder,inOrder,st,pos-1);
    root->right = buildTree(preOrder,inOrder,pos+1,ed);

    return root;
}

void prtInorder(Node* root){
    if(root==NULL){
        return;
    }

    prtInorder(root->left);
    cout<<root->data<<" ";
    prtInorder(root->right);
}

int main(){
    //Tree-1
    // int preOrder[] = {1,2,4,3,5};
    // int inOrder[] = {4,2,1,5,3};

    //Tree-2
    int preOrder[] = {1,2,4,5,3,6,7};
    int inOrder[] = {4,2,5,1,6,3,7};

    //Build Tree
    Node* root = buildTree(preOrder,inOrder,0,6);
    //Print
    prtInorder(root);


    return 0;
}