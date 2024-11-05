//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
  public:
    void inorderTrsl(Node* root, vector<int> &inorder){
        if(root==NULL){
            return;
        }    
        
        //LNR
        inorderTrsl(root->left, inorder);
        inorder.push_back(root->data);
        inorderTrsl(root->right, inorder);
    }
    
    void fillPostOrder(Node* root, vector<int> &inorder, int &idx){
        //base case
        if(root==NULL){
            return;
        }
        
        //L,R,N
        fillPostOrder(root->left, inorder, idx);
        fillPostOrder(root->right, inorder, idx);
        root->data = inorder[idx++];
        
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        //step1: get inorder
        vector<int> inorder;
        
        inorderTrsl(root, inorder);
        
        
        //step2: fill postorder into given bst
        int idx=0;
        fillPostOrder(root, inorder, idx);
        
    }    
};