class Solution {
  public:
    int countNodes(struct Node* root){
        //base case
        if(root==NULL){
            return 0;
        }
        
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root, int index, int cnt){
        if(root==NULL){
            return true;
        }
        
        if(index>=cnt){
            return false;
        }
        
        else{
            bool left = isCBT(root->left, 2*index+1, cnt);
            bool right = isCBT(root->right, 2*index+2, cnt);
            
            return (left and right);
        }
    }
    
    bool isMaxOrder(struct Node* root){
        //leaf node
        if(root->left == NULL and root->right==NULL){
            return true;
        }
        
        if(root->right==NULL){
            return (root->data>root->left->data);
        }
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return (left and right and (root->data>root->left->data and root->data>root->right->data));
        }
    }
    
    bool isHeap(struct Node* tree) {
        int index=0;
        int totalCount = countNodes(tree);
        
        if(isCBT(tree, index, totalCount) and isMaxOrder(tree)){
            return true;   
        }
        else{
            return false;
        }
    }
};

