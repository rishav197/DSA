class Solution {
public:
    void lvlOrderTrsl(TreeNode* root, vector<vector<int>> &ans){
        //base case
        if(root==NULL){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> out;
      

        while(!q.empty()){
            
            TreeNode* tmp = q.front();
            q.pop();
          

            if(tmp==NULL){
                //prev level completely traversed 
                ans.push_back(out);
                out.clear();

                if(!q.empty()){
                    //queue still has some child nodes
                    q.push(NULL);
                }
            }
            else{
                //traverse at a level
                out.push_back(tmp->val);

                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
        }

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> out;

        lvlOrderTrsl(root, ans);

        return ans;
    }
};