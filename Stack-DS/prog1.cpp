#include <bits/stdc++.h>
using namespace std;
/* Array based Stack Implementation */
/* 
1. push(x)
2. pop()
3. top()
4. empty()
*/
#define n 100

class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){

        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }

        top++;
        arr[top]=x;
    }

    void pop(){
        
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }

    int Top(){

        if(top==-1){
            cout<<"No element present"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

int main(){

    // Stack st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // cout<<st.Top()<<endl;
    // st.pop();
    // cout<<st.Top()<<endl;
    // st.pop();
    // st.pop();
    // st.pop();
    // cout<<st.empty()<<endl;

        
    // Stack st;
    // int N=100;
    
    // for(int i=1; i<=N; ++i){
    //     st.push(i);    
    // }

    // while(N!=-1){
    //     cout<<st.Top()<<" ";
    //     st.pop();
    //     N--;
    // }


    return 0;
}