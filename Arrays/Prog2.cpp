#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int mx=INT_MIN;
    cout<<"Running sum over array: "<<endl;
    for(int i=0; i<n; i++){
        mx=max(mx,arr[i]);
        cout<<mx<<" ";
    }
    return 0;
}