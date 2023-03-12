#include <bits/stdc++.h>
using namespace std;
/* Queue implementation of CPP STL*/

int main(){
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);

    cout<<qu.size()<<endl;
    cout<<"front = "<<qu.front()<<endl;
    cout<<"back = "<<qu.back()<<endl;

    while(!qu.empty()){
        cout<<qu.back()<<" ";
        qu.pop();
    } cout<<endl;
    
    cout<<!qu.empty()<<endl;



    return 0;
}