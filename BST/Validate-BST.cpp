/*
approach : using range for each node in the left & right subtree
*/

bool isBST(BinaryTreeNode<int> *root, int min, int max){
    //base case 
    if(root==NULL){
        return true;
    }
    if(root->data>=min and root->data<=max){
        bool leftAns = isBST(root->left, min, root->data);
        bool rightAns = isBST(root->right, root->data, max);

        return leftAns and rightAns;
    }
    else{
        return false;
    }

    
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root, INT_MIN, INT_MAX);
}