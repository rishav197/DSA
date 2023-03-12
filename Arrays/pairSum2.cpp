#include <bits/stdc++.h>
using namespace std;
/* Pair Sum Problem  [complexity --> O(n)]*/
// for this approach elements must be sorted else appr will fail

bool pairSum(int a[], int n, int k){
    int low=0; 
    int high=n-1;

    while(low<high){
        if(a[low]+a[high]==k){
            cout<<(low+1)<<" "<<(high+1)<<endl;
            return true;
        }
        else if(a[low]+a[high]>k){
            --high;
        }
        else{
            ++low;
        }
    }
    return false;
}

int main(){

    int a[] = {2,4,7,11,14,20,21}; //must be sorted
    int n = sizeof(a)/sizeof(a[0]);
    int k=35;

    cout<<pairSum(a,n,k)<<endl;

    return 0;
}