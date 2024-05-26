#include<iostream> 
#include<string>
#include<climits> 
#include <set>
using namespace std;

/*
Union & Intersection bw two sorted arrays
*/
void Union(int a[], int b[], int n1, int n2){
    set<int> s;
    for(int i=0; i<n1; i++){
        s.insert(a[i]);
    }

    for(int i=0; i<n2; i++){
        s.insert(b[i]);
    }

    //print Union
    set<int> ::iterator itr;
    itr=s.begin();
    while(itr!=s.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl; 
}

void intersection(int a[], int b[], int n1, int n2){
    int i=0,j=0;
    set<int> s;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            s.insert(a[i]);
            i++; j++;
        }
    } 

    //print Union
    set<int> ::iterator itr;
    itr=s.begin();
    while(itr!=s.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl;   
}

int main(){

    int a[] = {1,2,3,4};
    int b[] = {3,4,5,6};
    int n1=4;
    int n2=4;
    Union(a,b,n1,n2);
    intersection(a,b,n1,n2);


    return 0;
}