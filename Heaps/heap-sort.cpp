/*Leetcode problem, Heap Sort (lc-912)*/
class Solution {
public:
    void heapify(vector<int>& arr, int n, int idx){
        int largest = idx;
        int ltIdx = 2*idx+1;
        int rtIdx = 2*idx+2;
        
        if(ltIdx<n and arr[ltIdx]>arr[largest]){
            largest = ltIdx;
        }
        
        if(rtIdx<n and arr[rtIdx]>arr[largest]){
            largest = rtIdx; 
        }
        
        if(largest!=idx){
            swap(arr[idx], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(vector<int>& arr, int n){
        for(int idx=n/2-1; idx>=0; idx--){
            heapify(arr, n, idx);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        //build heap
        buildHeap(nums, n);

        //sort
        int size = n;
        while(size>1){
            //step1:
            swap(nums[0], nums[size-1]);
            size-=1;

            //step2:
            heapify(nums, size, 0);
        }

        return nums;
    }
};


/* by Codehelp tutorial */
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest=i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest] < arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n){

    int size = n;

    while(size>1){
        //step1: swap
        swap(arr[size], arr[1]);
        size--;

        //step2: 
        heapify(arr, size, 1);
    }
    
}

int main(){ 

    int arr[] = {-1, 54, 53, 55, 52, 50, -90, 33, 5, 85, 66};
    int n = 10;

    //heap creation
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout<<"Printing the array now"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heap sort
    heapSort(arr, n);

    cout<<"Printing the array now"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
   

    return 0;
}


