#include<iostream> 
#include<climits> 
#include<string>
using namespace std;
/* Printing String in reverse order or Reverse the string */


string reverse(string s, string news){
    if(s.length()==0){
        return news;
    }
    string ros = s.substr(1);
    news = s[0]+news;
    return reverse(ros,news);
}

int main(){
    
    string str = "RISHAV";
    string revStr=reverse(str,"");
    cout<<revStr<<endl;

    return 0;
}