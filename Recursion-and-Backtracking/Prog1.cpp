#include <bits/stdc++.h>

using namespace std;
/* Sum till n = n + n-1 + n-2 + .... + 2 + 1 
   Sum till 0 = 0 */

int Sum(int n){
    if(n==0)
        return 0;
    int prevTerm = Sum(n-1);
    return n+prevTerm;
}

int main(){
    int n; cin>>n;
    cout<<Sum(n)<<endl;

    return 0;
}