/*approach: using pair of (isSum, Sum)->(bool, int), O(N)*/

class Solution
{
    public:
    pair<bool, int> isSumTreeFast(Node* root){
        //base case
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        //leaf node
        if(root->left == NULL and root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool condition = (root->data == left.second + right.second);
        
        pair<bool, int> ans;
        
        if(leftAns and rightAns and condition){
            ans.first = true;
            ans.second = root->data + left.second + right.second;
        }
        else{
            ans.first = false;
            ans.second = root->data + left.second + right.second;

        }
        
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};