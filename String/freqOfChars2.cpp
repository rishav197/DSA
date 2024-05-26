#include <bits/stdc++.h>
using namespace std;
/*print all the indexes from the constructed
arr which have values greater than 1 
sample input: "geeksforgeeks"  */

int main(){
    string s = "geeksforgeeks";
    int n = s.size();

    map<char, int> mp;

    for(int i=0; i<n; ++i){
        mp[s[i]]+=1;
    }

    for(auto it=mp.begin(); it!=mp.end(); ++it){
        if((*it).second>1){
            // cout<<(*it).first<<" "<<(*it).second<<endl;
            cout<<(*it).first<<" ";
        }
    }
    cout<<endl;

    return 0;
}