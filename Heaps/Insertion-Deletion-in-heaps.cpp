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

    void deletefromHeap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        //step-1: put last element into first index
        arr[1]=arr[size];
        //step-2: remove last element
        size--;

        //step-3: take root node to its correct position
        int i=1;
        while(i<size){
            int leftIdx = 2*i;
            int rightIdx = 2*i+1;

            if(leftIdx < size && arr[i] < arr[leftIdx]){
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }
            else if(rightIdx < size && arr[i] < arr[rightIdx]){
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }
            else{
                return;
            }
        }

    }
};



int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    //print the heap
    h.print();

    h.deletefromHeap();
    h.print();
    
   

    return 0;
}