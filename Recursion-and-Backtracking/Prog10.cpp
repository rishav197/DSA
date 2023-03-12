#include<iostream> 
#include<climits> 
#include<string>
using namespace std;

/* Move all x to end of the string */
string moveallX(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = moveallX(s.substr(1));
    if(ch=='x'){
        return ans+ch; 
    }
    return ch+ans;
}

int main(){
    // cout<<moveallX("axxbdxcefxhix")<<endl;
    // cout<<moveallX("axxxbxxcxd")<<endl;
    return 0;
}