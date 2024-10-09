#include <bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[100];
    int size=0;

    void insert(int val){
        size = size+1;
        int idx = size;
        arr[idx]=val;

        while(idx>1){
            int parent = idx/2;

            if(arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]);
                idx=parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromHp(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        //step1: 
        arr[1]=arr[size];
        //step2:
        size--;

        //step3: propagate root to its correct position
        int idx=1;
        while(idx<size){
            int ltIdx = 2*idx;
            int rtIdx = 2*idx+1;

            if(ltIdx<size and arr[idx]<arr[ltIdx]){
                swap(arr[idx], arr[ltIdx]);
                idx=ltIdx;
            }
            else if(rtIdx<size and arr[idx]<arr[rtIdx]){
                swap(arr[idx], arr[rtIdx]);
                idx=rtIdx;
            }
            else{
                return;
            }
        }
    }


};

void heapify(int arr[], int n, int idx){
    int largest = idx;
    int ltIdx = 2*idx;
    int rtIdx = 2*idx+1;

    if(ltIdx<=n and arr[largest]<arr[ltIdx]){
        largest=ltIdx;
    }

    if(rtIdx<=n and arr[largest]<arr[rtIdx]){
        largest=rtIdx;
    }

    if(largest!=idx){
        swap(arr[largest], arr[idx]);
        heapify(arr, n, largest);
    }

}


void heapSort(int arr[], int n){
    //heap build 
    for(int idx=n/2; idx>0; idx--){
        heapify(arr, n, idx);
    }


    //sort logic
    int size = n;

    while(size>1){
        //algo 
        //step1: swap root node with the last node
        swap(arr[size], arr[1]); 
        size--;

        //step2: take root to its correct pos
        heapify(arr, size, 1);
    }
}

int main(){

    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);

    // //insertion - 50,55,53,52,54
    // //print the heap
    // h.print();

    // //deletion
    // h.deletefromHp();
    // h.print();

   /*----------------- Heapify algo --------------------------*/
    // int arr[] = {-1, 40, 50, 65, 72, 80};
    // int n = 5;


    // cout<<"Before Heapify"<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    
    // for(int i=n/2; i>0; i--){
    //     heapify(arr,n,i);
    // }

    // cout<<"After Heapify"<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    /*--------Heap Sort-----------*/
    int arr[] = {-1, 90, 55, 50, -60, 57, 89, 69, 54};
    int n = 8;

    //print before heapsort
    for(int idx=1; idx<=n; idx++){
        cout<<arr[idx]<<" ";
    }
    cout<<endl;

    //sort 
    heapSort(arr, n);

    //print after heapsort
    for(int idx=1; idx<=n; idx++){
        cout<<arr[idx]<<" ";
    }
    cout<<endl;


    return 0;
}