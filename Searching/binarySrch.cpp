#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/* Binary Search -- run time : O(logn) */

int binarySrch(int n, int arr[], int key){
    int s=0; //staring idx
    int e=n-1; //end idx

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
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
    cout<<binarySrch(n,arr,key)<<endl;

    return 0;
}
