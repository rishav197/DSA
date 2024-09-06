/*
tc -> O(NlogN), sc->O(N)
*/
class Solution {
  public:
    Node* createParentMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
        Node* res=NULL;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data==target){
                res=front;
            }
            
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        
        return res;
    }
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent, int &ans){
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root]=true;
        
        
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0; i<size; i++){
                //process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                if(front->left and !visited[front->left]){
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                
                if(front->right and !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }
                
                if(nodeToParent[front] and !visited[nodeToParent[front]]){
                    flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=1;
                }
            }
            
            if(flag==1){
                ans++;
            }
        }
        
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        /*
        algo: 
        step1: create nodeToParent mapping
        step2: find target node
        step3: burn the tree in min time
        */ 
        int ans=0;
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        burnTree(targetNode, nodeToParent, ans);
        
        return ans;
    }
};