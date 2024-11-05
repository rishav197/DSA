// User function Template for C++

class Solution{
    public:
    
    void heapify(vector<int> &arr, int N, int idx){
        //0 based indexing
        int largest = idx;
        int ltIdx = 2*idx+1; 
        int rtIdx = 2*idx+2;
        
        if(ltIdx<N and arr[ltIdx]>arr[largest]){
            largest = ltIdx;
        }
        
        if(rtIdx<N and arr[rtIdx]>arr[largest]){
            largest = rtIdx;
        }
        
        if(largest!=idx){
            swap(arr[idx], arr[largest]);
            heapify(arr, N, largest);
        }       
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c;
        
        //step1: merge two given arrays a & b into c
        for(auto item : a){
            c.push_back(item);
        }
        for(auto item : b){
            c.push_back(item);
        }
        
        
        //step2: heapify non leaf nodes
        int N = n+m;
        for(int idx=N/2-1; idx>=0; idx--){
            heapify(c, N, idx);
        }
        
        return c;
    }
};