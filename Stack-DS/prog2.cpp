// #include <bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;
/* Reverse the Sentence */
void reverseSentence(string s){
    stack<string> st;

    for(int i=0; i<s.length(); ++i){
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    //Print Stack
    while(!s.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){

    // stack<int> st;
    // for(int i=10; i<=100; i+=10){
    //     st.push(i);
    // }

    //print Stack
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    string s = "Hey, how are you doing";
    reverseSentence(s);


    return 0;
}