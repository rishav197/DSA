#include <bits/stdc++.h>
using namespace std;
/* Pointers in CPP */

void incrementer(int* a){
    *a += 50;
}

int main(){

    // int a=10;
    // int* aptr;
    // int* bptr;
    // int* cptr;
    // aptr=&a;
    // bptr=aptr;
    // cptr=bptr;

    // cout<<aptr<<endl;
    // cout<<*aptr<<endl;
    // cout<<*cptr-20<<endl;

    int num=80;
    incrementer(&num);
    cout<<num;

    return 0;
}