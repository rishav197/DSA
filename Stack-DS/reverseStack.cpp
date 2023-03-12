#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    stack<int> tmpSt1;
    stack<int> tmpSt2;
    while(!st.empty()){
        int ele = st.top();
        tmpSt1.push(ele);
        st.pop();
    }

    while(!tmpSt1.empty()){
        int ele = tmpSt1.top();
        tmpSt2.push(ele);
        tmpSt1.pop();
    }

    while(!tmpSt2.empty()){
        int ele = tmpSt2.top();
        st.push(ele);
        tmpSt2.pop();
    }
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // cout<<"Before Reversed Stack:"<<endl;
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;

    reverse(st);

    cout<<"Reversed Stack:"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;


    return 0;
}