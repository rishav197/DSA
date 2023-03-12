#include <bits/stdc++.h>
using namespace std;
/* Max sub arry sum -- by cumulative sum approach [complexity --O(n2)] */

int main(){

    int a[] = {1,-4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    int currSum[n+1];
    currSum[0]=0;

    for(int i=1; i<=n; ++i){
        currSum[i] = currSum[i-1] + a[i-1];
    }

    int mxsum = INT_MIN;
    for(int i=1; i<=n; ++i){
        int sum=0;
        for(int j=0; j<i; ++j){
            sum = currSum[i]-currSum[j];
            mxsum = max(sum, mxsum);
        }
    }

    cout<<mxsum<<endl;


    return 0;
}