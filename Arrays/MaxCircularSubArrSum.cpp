#include <bits/stdc++.h>
using namespace std;
/* Max Circular sub array sum */

int kadane(int a[], int n){
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0; i<n; ++i){
        currsum+=a[i];
        if(currsum<0){
            currsum=0;
        }
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}


int main(){

    // int a[]={4,-4,6,-6,10,-11,12};
    // int a[]={-4,-4,-6,-6,-10,-11,12};
    int n = sizeof(a)/sizeof(a[0]);

    int wrapsum;
    int nonwrapsum;

    nonwrapsum = kadane(a,n);
    int totalsum=0;
    for(int i=0; i<n; ++i){
        totalsum+=a[i];
        a[i]=-a[i];
    }

    wrapsum = totalsum + kadane(a,n);
    int mx = INT_MIN;
    if(max(wrapsum, nonwrapsum)==0){
        for(int i=0; i<n; ++i){
            a[i]=-a[i];
            mx=max(mx,a[i]);
        }
        cout<<mx<<endl;
    }
    else{
        cout<<max(wrapsum, nonwrapsum)<<endl;
    }
    


    return 0;
}