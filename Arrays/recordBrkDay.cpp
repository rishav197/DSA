#include <bits/stdc++.h>
using namespace std;


int main(){

    int n; cin>>n; //size of the arr
    int arr[n+1];
    arr[n]=-1; //last ele of the arr

    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }

    if(n==1){
        cout<<1<<endl;
    }

    int ans=0;
    int mx=INT_MIN;
    for(int i=0; i<n; ++i){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            ans+=1;
        }
        mx = max(arr[i], mx);
    }
    cout<<ans<<endl;




    return 0;
}