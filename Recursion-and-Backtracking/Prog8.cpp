#include<iostream>
using namespace std;
/* first and last occurence of a num in the array */
int fstOcc(int arr[], int n, int idx, int key){
    if(idx==n)
        return -1;
    if(arr[idx]==key)
        return idx;
    
    return fstOcc(arr, n, idx+1, key);
}

int lstOcc(int arr[], int n, int idx, int key){
    if(idx==n)
        return -1;
    int restArr = lstOcc(arr,n,idx+1,key);
    if(restArr!=-1)
        return restArr;
    if(arr[idx]==key)
        return idx;

    return -1;
}

int main(){
    int arr[] = {4,2,1,-2,5,-2,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<fstOcc(arr,n,0,4)<<endl;
    cout<<lstOcc(arr,n,0,4)<<endl;
    return 0;
}