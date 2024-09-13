/*
tc - O(N), sc - O(N)
*/

void inorderTrsl(BinaryTreeNode<int>* root, vector<int> &inorder){
    //base case
    if(root==NULL){
        return;
    }

    //LNR
    inorderTrsl(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrsl(root->right, inorder);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	
    vector<int> inorder;
    inorderTrsl(root, inorder);

    int i=0;
    int j=inorder.size()-1;

    while(i<j){
        int sum = inorder[i]+inorder[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j-=1;
        }
        else{
            i+=1;
        }
    }

    return false;

}