class info{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode* root, int &ans){
    //base case
    if(root==NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curNode;

    curNode.size = left.size + right.size + 1;
    curNode.maxi = max(root->data, right.maxi);
    curNode.mini = min(root->data, left.mini);

    if(left.isBST and right.isBST and (left.maxi<root->data and root->data<right.mini)){
        curNode.isBST = true;
    }
    else{
        curNode.isBST = false;
    }

    //answer update
    if(curNode.isBST){
        ans = max(ans, curNode.size);
    }

    return curNode;
}

int largestBST(TreeNode * root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    
    return maxSize;
}