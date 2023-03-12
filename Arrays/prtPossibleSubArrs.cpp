#include <bits/stdc++.h>
using namespace std;
/* Prt Possible sub arrays, max sum sub array */

int main(){

    int a[] = {-1,4,7,2};
    int n = sizeof(a)/sizeof(a[0]);
    int mx=INT_MIN;


    for(int i=0; i<n; ++i){

        for(int j=i; j<n; ++j){
            int sum=0;
            for(int k=i; k<=j; ++k){
                // cout<<a[k]<<" ";
                sum+=a[k];
            }
            cout<<"Sum = "<<sum;
            mx=max(mx, sum);
            cout<<endl;
        }
    }

    cout<<"Max Sum = "<<mx<<endl;

    return 0;
}