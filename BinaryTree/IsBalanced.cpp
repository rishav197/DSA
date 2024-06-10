/* approach-1: using helper height method, tc->O(n^2) */

class Solution{
    public:
    int height(struct Node* node){
        //base case
        if(node==NULL){
            return 0;
        }
        
        int ht_left_subtree = height(node->left);
        int ht_right_subtree = height(node->right);
        
        int ans = max(ht_left_subtree, ht_right_subtree) + 1;
        
        
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //base case
        if(root==NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left)-height(root->right))<=1;
        
        if(left and right and diff){
            return true;
        } 
        
        return false;
    }
};



/* approach-2: using pair of (isBalance, height), tc->O(n) */


class Solution{
    public:

    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node *root){
        //base case
        if(root == NULL){
            pair<bool, int> pr = {true,0};
            return pr;
        }
        
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns and rightAns and diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};