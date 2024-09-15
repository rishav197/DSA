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

TreeNode<int>* inorderToBST(int st, int ed, vector<int> &inorder){
    //base case
    if(st>ed){
        return NULL;
    }

    int mid = (st+ed)/2;

    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);

    //build LST
    root->left = inorderToBST(st, mid-1, inorder);

    //build RST
    root->right = inorderToBST(mid+1, ed, inorder);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    //store inorder
    inorderTrsl(root, inorder);
    int st = 0;
    int ed = inorder.size()-1;

    return inorderToBST(st, ed, inorder);
}
