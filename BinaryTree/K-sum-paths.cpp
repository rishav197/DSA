class Solution {
  public:
    void solve(Node* root, int k, int &count, vector<int> &path){
        //base case
        if(root==NULL){
            return;
        }
        
        path.push_back(root->data);
        
        //call for left subtree
        solve(root->left,k,count,path);
        
        //call for right subtree
        solve(root->right,k,count,path);
        
        //check for sum equal to k
        int sum=0;
        for(int idx=path.size()-1; idx>=0; idx--){
            sum += path[idx];
            if(sum==k){
                ++count;
            }
        }
        
        path.pop_back(); //when move back to parent node 
    }
    
    int sumK(Node *root, int k) {
        vector<int> path;
        int count=0;
        solve(root,k,count,path);
        return count;
        
    }
};