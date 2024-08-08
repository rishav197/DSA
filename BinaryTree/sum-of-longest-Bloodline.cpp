/* 
tc -> O(N), sc -> O(height)
*/
class Solution
{
public:

    void solve(Node* root, int sum, int &mxsum, int len, int &mxlen){
        //base case 
        if(root==NULL){
            if(len>mxlen){
                mxlen=len;
                mxsum=sum;
            }
            else if(len==mxlen){
                mxsum = max(sum, mxsum);
            }
            return;
        }
        
        sum += root->data;
        solve(root->left,sum,mxsum,len+1,mxlen); //call for left
        solve(root->right,sum,mxsum,len+1,mxlen); //call for right
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum=0;
        int mxsum=INT_MIN;
        
        int len=0;
        int mxlen=0;
        
        solve(root,sum,mxsum,len,mxlen);
        
        return mxsum;
        
    }
};