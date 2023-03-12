#include <bits/stdc++.h>
using namespace std;
/* Calculate n^p power=p, base=n */

int pow(int n, int p){
    if(p==0)
        return 1;
    if(n==0)
        return 0;

    return n*pow(n, p-1);
}
int main(){
    int n; cin>>n;
    int p; cin>>p;
    cout<<pow(n,p);

    return 0;
}