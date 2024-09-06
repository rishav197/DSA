/* 
approach 1 : Without using map for finding position, tc->O(N^2) sc->O(N)
approach 2 : With using map for finding position, tc->O(N), sc->O()
*/

/* approach-1*/
class Solution{
    public:
    int findPosition(int in[], int element, int n){
        for(int i=0; i<n; i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &idx, int inorderSt, int inorderEd, int n){
        //base case
        if(idx>=n or inorderSt>inorderEd){
            return NULL;
        }
        
        int element = pre[idx++];
        Node* root = new Node(element);
        int pos = findPosition(in, element, n);
        
        //recursive calls (Call for left and Right)
        root->left = solve(in,pre,idx,inorderSt,pos-1,n);
        root->right = solve(in,pre,idx,pos+1,inorderEd,n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderidx =0;
        Node* ans = solve(in, pre, preOrderidx, 0, n-1, n);
        return ans;
        
    }
};




/* approach-2*/

class Solution{
    public:
    void createMapping(int in[], map<int,int> &nodeToIdx, int n){
        for(int i=0; i<n; i++){
            nodeToIdx[in[i]]=i;
        }
    }
    
    Node* solve(int in[], int pre[], int &idx, int inorderSt, int inorderEd, int n, map<int,int> &nodeToIdx){
        //base case
        if(idx>=n or inorderSt>inorderEd){
            return NULL;
        }
        
        int element = pre[idx++];
        Node* root = new Node(element);
        int pos = nodeToIdx[element];
        
        //recursive calls (Call for left and Right)
        root->left = solve(in,pre,idx,inorderSt,pos-1,n,nodeToIdx);
        root->right = solve(in,pre,idx,pos+1,inorderEd,n,nodeToIdx);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderidx =0;
        map<int,int> nodeToIdx;
        
        //create node to idx mapping
        createMapping(in, nodeToIdx, n);
        Node* ans = solve(in, pre, preOrderidx, 0, n-1, n, nodeToIdx);
        return ans;
        
    }
};