#include<iostream>
/* Linear Search algo -- run time : O(n) */
using namespace std;

int linearSrch(int n, int arr[], int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n; cin>>n;
    int arr[n]; // array declaration

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;
    cout<<linearSrch(n,arr,key)<<endl;

    return 0;
}