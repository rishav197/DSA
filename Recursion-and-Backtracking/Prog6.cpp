#include<iostream>
using namespace std;

bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool roa = sorted(arr+1, n-1); // rest of Array
    return (arr[0]<arr[1] && roa);
}

int main(){
    int arr[] = {-1,2,3,4,5, 6, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sorted(arr, n);   

    return 0;
}