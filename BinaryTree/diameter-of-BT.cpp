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


/*
Approach-2: TC -> O(N), using pair<int,int> of (Diameter,Height)
*/https://youtu.be/Ez8F0nW6S-w?si=gO9HRfzlijb0pKsihttps://youtu.be/Ez8F0nW6S-w?si=gO9HRfzlijb0pKsihttps://youtu.be/Ez8F0nW6S-w?si=gO9HRfzlijb0pKsihttps://youtu.be/Ez8F0nW6S-w?si=gO9HRfzlijb0pKsihttps://youtu.be/Ez8F0nW6S-w?si=gO9HRfzlijb0pKsihttps://youtu.be/Ez8F0nW6S-w?si=gO9HRfzlijb0pKsi
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

    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right); 
        
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(opt1, max(opt2,opt3));
        ans.second = max(left.second, right.second)+1;
        
        return ans;
    }
    
    int diameter(Node* root) {
        
        return diameterFast(root).first;
    }
};


