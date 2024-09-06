/*
approach-2: Using Map, tc->O(N), sc->O(N)
*/

class Solution {
  public:
    void createMapping(int in[], map<int,int> &nodeToIdx, int n){
        for(int i=0; i<n; i++){
            nodeToIdx[in[i]]=i;
        }
    }
    
    Node* solve(int in[], int post[], int &idx, int inorderSt, int inorderEd, int n, map<int,int> &nodeToIdx){
        //base case
        if(idx<0 or inorderSt>inorderEd){
            return NULL;
        }
        
        int element = post[idx--];
        Node* root = new Node(element);
        int pos = nodeToIdx[element];
        
        //recursive calls (Call for left and Right)
        root->right = solve(in,post,idx,pos+1,inorderEd,n,nodeToIdx);
        root->left = solve(in,post,idx,inorderSt,pos-1,n,nodeToIdx);
        
        return root;
    }
    
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderidx = n-1;
        map<int,int> nodeToIdx;
        
        //create node to idx mapping
        createMapping(in, nodeToIdx, n);
        Node* ans = solve(in, post, postOrderidx, 0, n-1, n, nodeToIdx);
        return ans;
    }
};