#include <bits/stdc++.h>
using namespace std;

long long int merge(int arr[], int l, int mid, int r){
    long long int count=0; 
    int n1 = mid-l+1;
    int n2 = r-mid;

    //this is for first commit
    int a[n1];
    int b[n2];
    for(int i=0; i<n1; ++i){
        a[i] = arr[l+i];
    }
    for(int i=0; i<n2; ++i){
        b[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=l;
    while(i<n1 and j<n2){
        if(a[i]<=b[j]){
            arr[k] = a[i];
            k++; i++;
        }
        else{
            arr[k] = b[j];
            count += n1-i;
            k++; j++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k] = b[j];
        k++; j++;
    }

    return count;
}

long long int mergeSort(int arr[], int l, int r){
    long long int count=0;
    if(l<r){
        int mid = (l+r)/2;
        count += mergeSort(arr,l,mid);
        count += mergeSort(arr,mid+1,r);
        count += merge(arr,l,mid,r);
    }
}

int main(){
    int arr[] = {3,5,6,9,1,2,7,8};
    int n = 8;

    cout<<mergeSort(arr,0,n-1);


    return 0;
}