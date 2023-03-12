#include <bits/stdc++.h>
using namespace std;
/* Implementation of the Kadane's Algorithm */

int main(){

    int a[] = {-1,4,-6,7,-4};
    // int a[] = {-1,-2,-3,-4,-5};    
    int n = sizeof(a)/sizeof(a[0]);

    int mxsum=INT_MIN;
    int currsum=0;
    for(int i=0; i<n; ++i){
        currsum=currsum+a[i];
        if(currsum<0){
            currsum=0;
        }
        mxsum=max(mxsum, currsum);
    }
    int mx=a[0];
    if(mxsum==0){
        for(int i=0; i<n; ++i){
            mx = max(mx, a[i]);
        }

        cout<<mx<<endl;
    }
    else{
        cout<<mxsum<<endl;
    }




    return 0;
}