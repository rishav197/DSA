#include <bits/stdc++.h>
// #include<queue>
using namespace std;



int main(){
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at top: "<<pq.top()<<endl;




    priority_queue<int, vector<int>, greater<int>> minhp;

    minhp.push(40);
    minhp.push(20);
    minhp.push(50);
    minhp.push(30);

    cout<<"min heap"<<endl;
    while(!minhp.empty()){
        cout<<minhp.top()<<" ";
        minhp.pop();
    }
    cout<<endl;

    cout<<"Size : "<<minhp.size()<<endl;
   

    return 0;
}