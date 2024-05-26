#include<bits/stdc++.h>
using namespace std;
/* Fibonacci num: fib(n) = fib(n-1) + fib(n-2) 
   Base case : fib(0)=0, fib(1)=1 
   */

int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int fst_term = fib(n-1);
    int sec_term = fib(n-2);
    int curr_term = fst_term+sec_term;
    return curr_term;
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cout<<fib(i)<<" ";
    }
   
    return 0;
}