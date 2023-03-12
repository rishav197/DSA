#include<iostream> 
#include<climits> 
#include<string>
using namespace std;

/* Print all possible sub sequence of the string */
// void subseq(string s, string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     char ch = s[0];
//     string ros = s.substr(1);
//     subseq(ros, ans + ch); // include a string
//     subseq(ros, ans); // not include a string
// }

/* Print all possible subsequence with ascii values */
void subseq(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    subseq(ros, ans); // not include a string
    subseq(ros, ans + ch); // include a string
    subseq(ros, ans+to_string(code));
}
int main(){
    subseq("AB","");

    return 0;
}