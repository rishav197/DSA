#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int idx){
    int largest = idx;
    int ltIdx = 2*idx+1;
    int rtIdx = 2*idx+2;

    //compare with left and right
    if(ltIdx<n and arr[ltIdx]>arr[largest]){
        largest=ltIdx;
    }

    if(rtIdx<n and arr[rtIdx]>arr[largest]){
        largest=rtIdx;
    }

    if(largest != idx){
        swap(arr[idx], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){

    for(int idx=n/2-1; idx>=0; idx--){
        heapify(arr, n, idx);
    }
}

void prtHeap(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
}

int main(){


    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"n = "<<n<<endl;

    //build heap  
    buildHeap(arr, n);

    //print heap 
    prtHeap(arr, n);


    return 0;
}