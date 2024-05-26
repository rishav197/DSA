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

    // cout<<arr[n-1]<<endl;

    int min, max;
    min=INT_MAX;
    max=INT_MIN;
    // cout<<max<<" "<<min<<endl;

    for(int i=0; i<n; i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Min = "<<min<<endl;
    cout<<"Max = "<<max<<endl;

    
    return 0;
}