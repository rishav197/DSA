#include<iostream> 
#include<climits> 
#include<string>
using namespace std;

string keyPadArr[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keyPad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    string code = keyPadArr[ch-'0'];
    cout<<"Code = "<<code<<endl;
    
    for(int i=0; i<code.length(); i++){
        keyPad(ros,ans+code[i]);
    }
}

int main(){
    keyPad("28","");

    return 0;
}