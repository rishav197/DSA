#include <bits/stdc++.h>
using namespace std;
/**/

int main(){

    string s = "abbcdxyyyy";
    int freq[26];
    for(int i=0; i<26; ++i){
        freq[i]=0;
    }

    for(int i=0; i<s.size(); i++){
        // cout<<s[i]-'a'<<endl;
        int key=s[i]-'a';
        freq[key]++;
    }

    char ans='a';
    int mx=0;
    for(int i=0; i<26; ++i){
        if(freq[i]>mx){
            mx=freq[i];
            ans = i+'a';
            // cout<<ans<<endl;
        }
    }

    cout<<ans<<"->"<<mx<<endl;


    return 0;
}