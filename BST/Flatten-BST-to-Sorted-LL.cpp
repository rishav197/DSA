void inorderTrsl(TreeNode<int> * root, vector<int> &inorder){
    //base case
    if(root==NULL){
        return;
    }

    //LNR
    inorderTrsl(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrsl(root->right, inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    //step 1 
    vector<int> inorder;
    inorderTrsl(root, inorder);

    int n = inorder.size();

    TreeNode<int>* newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int>* cur = newRoot;

    //step 2
    for(int idx=1; idx<n; idx++){

        TreeNode<int>* tmp = new TreeNode<int>(inorder[idx]);

        cur->left = NULL;
        cur->right = tmp;
        cur = cur->right;
    }
    
    //step 3
    cur->left=NULL;
    cur->right=NULL;

    return newRoot;
}
