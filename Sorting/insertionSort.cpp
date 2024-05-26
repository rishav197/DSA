#include<iostream>
using namespace std;
/* Insertion Sort */
// n=5, 40 30 25 90 10 i=0 to i=4


int main(){
    int n; cin>>n;
    int arr[n];

    // initialisation
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<n; i++){
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr && j>=0){
            arr[j+1]=arr[j];
            j--; 
        }
        arr[j+1]=curr;
    }

    // Print Array 
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}