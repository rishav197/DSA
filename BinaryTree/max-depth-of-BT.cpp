/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){ //base case
            return 0;
        }

        int ht_lst = maxDepth(root->left); //Call for Left Subtree
        int ht_rst = maxDepth(root->right); //Call for Right Subtree
        int ht = max(ht_lst, ht_rst)+1;

        return ht;
    }
};