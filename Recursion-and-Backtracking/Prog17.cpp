#include<iostream> 
#include<string>
#include<climits> 
using namespace std;

int frdsPairing(int n){ //friendsPairing
    if(n==0 || n==1 || n==2){
        return n;
    }
    return frdsPairing(n-1)+frdsPairing(n-2)*(n-1);
}

int main(){
    cout<<frdsPairing(4);
    return 0;
}