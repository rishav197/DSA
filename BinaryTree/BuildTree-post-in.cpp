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

int srch(int inOrder[],int val,int st,int ed){
    for(int idx=st; idx<=ed; idx++){
        if(inOrder[idx]==val){
            return idx;
        }
    }
    return -1;
}

Node* buildTree(int postOrder[],int inOrder[],int st,int ed){
    static int idx=0;
    if(st>ed){
        return NULL;
    }
    int curr = postOrder[idx];
    idx--;
    Node* root = new Node(curr);
    if(st==ed){
        return root;
    }

    int pos = srch(inOrder,curr,st,ed);
    root->right = buildTree(postOrder,inOrder,pos+1,ed);
    root->left = buildTree(postOrder,inOrder,st,pos-1);

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

    int postOrder[] = {4,2,5,3,1};
    int inOrder[] = {4,2,1,5,3};

    Node* root = buildTree(postOrder,inOrder,0,4);

    //print 
    prtInorder(root);


    return 0;
}