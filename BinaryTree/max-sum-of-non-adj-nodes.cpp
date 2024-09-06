/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        //base case 
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> ltAns = solve(root->left);
        pair<int,int> rtAns = solve(root->right);
        
        
        pair<int,int> rslt;
        
        //include the curr node
        rslt.first = root->data + ltAns.second + rtAns.second;
        
        //exclude the curr node
        rslt.second = max(ltAns.first, ltAns.second) + max(rtAns.first, rtAns.second);
        
        return rslt;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};