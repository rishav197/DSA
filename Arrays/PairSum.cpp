#include <bits/stdc++.h>
using namespace std;
/* Pair Sum Problem  [complexity --> O(n^2)]*/

bool pairSum(int a[], int n, int k){
    for(int i=0; i<n; ++i){

        for(int j=i+1; j<n; ++j){
            if(a[i]+a[j]==k){
                cout<<i+1<<" "<<j+1<<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){

    int a[] = {2,4,7,11,14,16,20,21};
    int n = sizeof(a)/sizeof(a[0]);
    int k=41;

    cout<<pairSum(a,n,k)<<endl;

    return 0;
}