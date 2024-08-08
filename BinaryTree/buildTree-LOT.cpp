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


void buildTree(Node* &root){
    queue<Node*> q;

    cout<<"Enter the Data: ";
    int data;
    cin>>data;

    root = new Node(data);
    q.push(root);

    //algo starts from here
    while(!q.empty()){
        Node* topNode = q.front();
        q.pop();

        cout<<"Enter Data in the left of "<<topNode->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            topNode->left = new Node(leftData);
            q.push(topNode->left);
        }


        cout<<"Enter Data in the right of "<<topNode->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            topNode->right = new Node(rightData);
            q.push(topNode->right);
        }

    }
}

void preOrder(Node* root){
    if(root==NULL){ //NLR
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){

    Node* root = NULL;
    buildTree(root); //tree build up

    preOrder(root); //prt to cross check 
    
   

    return 0;
}