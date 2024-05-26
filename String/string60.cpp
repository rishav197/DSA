#include <bits/stdc++.h>
using namespace std;
/*NOT Completed */

bool checkStrings(string &s1, string &s2){
    // if(s1.length()!=s2.length()){
    //     return false;
    // }

    bool ans=false;
    string tmp = s1+s2;
    int n = tmp.size();

    auto reply = tmp.find(s2);
    if(reply!=string :: npos){
        ans=true;
    }

    return ans;
}

int main(){
    string s1 = "ABCD";
    string s2 = "ACBD";

    cout<<checkStrings(s1,s2);

    return 0;
}