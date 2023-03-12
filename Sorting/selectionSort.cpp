#include<iostream>
using namespace std;
/* Selection Sort */

int main(){
    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    // Sorting
    for(int i=0; i<n-1; i++){ // i start form i=0, j start from j=0+1

        for(int j=i+1; j<n; j++){

            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    // print
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}