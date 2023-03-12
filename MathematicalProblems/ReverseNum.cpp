#include <bits/stdc++.h>
using namespace std;

int reverseNum(int n){
    int reverse=0;
    while(n>0){
        int lstdgt=n%10; //get lastdigit
        reverse = reverse*10+lstdgt;
        n=n/10; //go to left digit towards leftside
    }
    return reverse;
}

int main(){
    int n=15398;
    cout<<reverseNum(n);

    return 0;
}