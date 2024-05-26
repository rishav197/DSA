#include <bits/stdc++.h>
using namespace std;
/* Pascal Triangle */


int fact(int n){
    if(n==0 or n==1){
        return 1;
    }

    return n*fact(n-1);
}

int main(){

    int n=6;

    //Pascal Triangle
    for(int i=0; i<n; ++i){

        for(int j=0; j<=i; ++j){
            cout<<fact(i)/(fact(i-j)*fact(j))<<" ";
        }
        cout<<endl;
    }



    return 0;
}