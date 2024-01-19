/*
Approach-1: TC -> O(N^2)
*/

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(struct Node* node){
        if(node==NULL){
            return 0;
        }
        
        int ht_lst = height(node->left);
        int ht_rst = height(node->right);
        int ht = max(ht_lst, ht_rst)+1;
        
        return ht;
    }
    
    int diameter(Node* root) {
        //base case
        if(root==NULL){
            return 0;
        }
        
        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->left) + 1 + height(root->right);
        
        return max(max(opt1, opt2), opt3);
    }
};


