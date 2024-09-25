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
   

    return 0;
}