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