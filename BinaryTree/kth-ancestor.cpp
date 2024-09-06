/* approach1: Using the vector to track nodes */
/* approach2: without using the vector to track nodes */

Node* solve(Node* root, int &k, int node){
    //base cases
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==node){
        return root;
    }
    
    //call for left
    Node* ltAns = solve(root->left,k,node);
    //call for right
    Node* rtAns = solve(root->right,k,node);
    
    
    //Return calls
    if(ltAns!=NULL and rtAns==NULL){
        k--;
        if(k<=0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return ltAns;
    }
    if(ltAns==NULL and rtAns!=NULL){
        k--;
        if(k<=0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rtAns;
    }
    
    return NULL;
    
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root,k,node);
    if(ans==NULL or ans->data==node){
        return -1;
    }
    
    return ans->data;
}