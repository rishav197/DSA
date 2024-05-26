#include <bits/stdc++.h>
using namespace std;
/* idx of first smallest occurance */


int main(){

    int arr[] = {1,2,83,4,3,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    const int N = 1e5+2;
    // cout<<N<<endl;
    int idx[N];
    for(int i=0; i<N; ++i){
        idx[i]=-1;
    }

    int mnidx = INT_MAX;

    for(int i=0; i<n; ++i){
        if(idx[arr[i]]!=-1){
            mnidx=min(mnidx,idx[arr[i]]);
        }
        else{
            idx[arr[i]]=i;
        }
    }

    if(mnidx==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<mnidx+1<<endl;
    }

    return 0;
}