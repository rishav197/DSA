#include <bits/stdc++.h>
using namespace std;
/* Level Order Traversal */

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


void prtLevelOrder(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL); cout<<endl;
        }
    }
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);

    prtLevelOrder(root);

    return 0;
}