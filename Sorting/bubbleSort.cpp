#include<iostream>
using namespace std;
/* Bubble Sort */
// n=5, 10 40 30 25 90 i=0 to i=4

int main(){
    int n; cin>>n;
    int arr[n];

    // Arr initialisation
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int count=1;
    while(count<n){
        for(int i=0; i<n-count; i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;
    }

    // Print array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}