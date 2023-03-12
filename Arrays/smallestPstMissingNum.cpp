#include <bits/stdc++.h>
using namespace std;
/* Smalles positive missing number */


int main(){

    int a[] = {0,-9,1,3,-4,5};
    int n = sizeof(a)/sizeof(a[0]);

    const int N=1e6+2;
    // cout<<N<<endl;
    bool check[N];
    for(int i=0; i<N; ++i){
        check[i]=false;
    }

    for(int i=0; i<n; ++i){
        if(a[i]>=0){
            check[a[i]]=true;
        }
    }

    int ans=-1;
    for(int i=1; i<N; ++i){
        if(check[i]==false){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}