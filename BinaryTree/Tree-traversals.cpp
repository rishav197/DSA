void inOrder(TreeNode* root, vector<int> &out1){
    if(root==NULL){
        return;
    }

    inOrder(root->left, out1);
    out1.push_back(root->data);
    inOrder(root->right, out1);
}

void preOrder(TreeNode* root, vector<int> &out2){
    if(root==NULL){ //NLR
        return;
    }

    out2.push_back(root->data);
    preOrder(root->left, out2);
    preOrder(root->right, out2);
}


void postOrder(TreeNode* root, vector<int> &out3){
    if(root==NULL){ //LRN
        return;
    }
    
    postOrder(root->left, out3);
    postOrder(root->right, out3);
    out3.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){

    vector<vector<int>> ans;
    vector<int> out1; // inorder -> LNR
    vector<int> out2; // preorder -> NLR
    vector<int> out3; // postorder -> LRN


    inOrder(root, out1);
    ans.push_back(out1);

    preOrder(root, out2);
    ans.push_back(out2);

    postOrder(root, out3);
    ans.push_back(out3);

    return ans;
}