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

int srch(int inOrder[],int curr,int st,int ed){
    for(int i=st; i<=ed; ++i){
        if(inOrder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postOrder[],int inOrder[],int st,int ed){
    static int idx=0;
    if(st>ed){
        return NULL;
    }

    int curr=postOrder[idx];
    idx--;
    Node* node = new Node(curr);

    if(st==ed){
        return node;
    }
    int pos = srch(inOrder,curr,st,ed);
    node->left = buildTree(postOrder,inOrder,st,pos-1);
    node->right = buildTree(postOrder,inOrder,pos+1,ed);

    return node;
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

    int postOrder[] = {4,3,6,2,1};
    int inOrder[] = {4,3,2,6,1};

    Node* root = buildTree(postOrder,inOrder,0,4);
    prtInorder(root);

    return 0;
}