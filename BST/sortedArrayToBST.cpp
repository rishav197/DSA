#include <bits/stdc++.h>
using namespace std;
/*Build Balanced BST from Sorted Array*/
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

Node* sortedArrToBST(int arr[], int st, int ed){
    if(st>ed){
        return NULL;
    }
    int mid = st+(ed-st)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrToBST(arr,st,mid-1);
    root->right = sortedArrToBST(arr,mid+1,ed);

    return root;
}

void preOrderPrt(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderPrt(root->left);
    preOrderPrt(root->right);
}

void inOrderPrt(Node* root){
    if(root==NULL){
        return;
    }

    preOrderPrt(root->left);
    cout<<root->data<<" ";
    preOrderPrt(root->right);
}

int main(){
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    Node* root = sortedArrToBST(arr,0,n-1);
    preOrderPrt(root); 
    cout<<endl;
    inOrderPrt(root);

    return 0;
}