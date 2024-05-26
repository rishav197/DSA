#include <bits/stdc++.h>
using namespace std;
/*Sub array with given sum*/


int main(){
    int s=18;
    int a[] = {1,2,3,5,7};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<n<<endl;
    
    int i=0, j=0; 
    int st=0-1, ed=0-1; 
    int sum=0;
    while(j<n && sum+a[j]<=s){
        sum+=a[j];
        ++j;
    }

    if(sum==s){
        st=i+1; ed=j;
        cout<<st<<" "<<ed<<endl;
        return 0;
    }

    while(j<n){
        sum+=a[j];
        while(sum>s){
            sum-=a[i];
            i++;
        }
        if(sum==s){
            st=i+1;
            ed=j+1;
            break;
        }
        j++;
    }

    cout<<st<<" "<<ed<<endl;

    return 0;
}