// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(struct Node* root){
        if(root==NULL){
            return 0;
        }
        
        int sum = 1 + countNodes(root->left) + countNodes(root->right);
        return sum;
    }
    
    bool isCBT(struct Node* root, int idx, int totalNodes){
        if(root==NULL){
            return true;
        }   
        
        if(idx>=totalNodes){
            return false;
        }
        
        bool left = isCBT(root->left, 2*idx+1, totalNodes);
        bool right = isCBT(root->right, 2*idx+2, totalNodes);
        
        return left and right;
    }
    
    bool isMaxOrder(struct Node* root){
        //leaf node
        if(root->left==NULL and root->right==NULL){
            return true;
        }
        
        //only left child exist
        if(root->right==NULL){
            return root->data > root->left->data;
        }
        
        else{ //both child exist
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return left and right and ((root->data > root->left->data) and (root->data > root->right->data));
        }
    }
    
    bool isHeap(struct Node* tree) {
        int idx=0;
        int totalNodes = countNodes(tree);
        
        if(isCBT(tree,idx,totalNodes) and isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
        
    }
};