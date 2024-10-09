
class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i){
        // 0 based indexing 
        int largest=i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<n && arr[largest] < arr[left]){
            largest=left;
        }
        if(right<n && arr[largest] < arr[right]){
            largest=right;
        }

        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }

    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        //step1: merge both arrays into one
        vector<int> ans;

        for(auto i: a){
            ans.push_back(i);
        }
        
        for(auto i: b){
            ans.push_back(i);
        }
        
        
        //step2: build heap using merged array
        int size = ans.size();
        for(int idx=size/2-1; idx>=0; idx--){
            heapify(ans, size, idx);
        }
        
        return ans;
    }
};