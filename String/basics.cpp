#include <bits/stdc++.h>
using namespace std;

/*String Ques*/

int main(){
    /*Method 1*/
    // string str;

    // cin>>str;
    // cout<<str;

    /*Method 2*/
    // string str = "ApniKaksha";
    // cout<<"str = "<<str;

    /*Method-3*/
    // string str;
    // getline(cin,str);
    // cout<<str;


    /*Method-4*/
    // string str1(5,'A');
    // cout<<str1<<endl;
    // cout<<"Len = "<<str1.length()<<endl;


    // string s1 = "abc";
    // string s2 = "ABC";


    // s1.append(s2);
    // cout<<s1<<endl;

    // cout<<s1[3]<<endl;

    // cout<<s1.length()<<endl;

    // s1.clear();
    // cout<<s1.length();

    // Clearing string 
    // string str = "abcde";
    // str.clear();
    // cout<<str<<endl;


    //Comparing string 
    // string s1 = "abc";
    // string s2 = "abc";
    // cout<<s1.compare(s2)<<endl;

    // if(s1.compare(s2)==0){
    //     cout<<"Both strings equal"<<endl;
    // } else{
    //     cout<<"NOT equal"<<endl;
    // }


    // Erase Method 
    // string str = "nincompoop";
    // str.erase(6,4); // 1st attri-->start idx, 2nd attri--> length
    // cout<<str<<endl;


    // INERT method
    // string str = "nincompoop"; 
    // str.insert(3,"poop");
    // cout<<str;



    //Iteration over a string 
    // string s1 = "nincompoop";
    // string s = s1.substr(0,5); //strt idx, length
    // cout<<s;


    // String to int Conversion
    // string s = "120";
    // int x = stoi(s);
    // cout<<x+5;


    // Int to String Conversion
    // int x = 786;
    // cout<< to_string(x)+"2"<<endl;


    //Sorting String
    // string s1 = "zxywvu";
    // sort(s1.begin(), s1.end());
    // cout<<s1;
    // cout<<s1.empty()<<endl;
    // s1.clear();
    // cout<<s1.empty()<<endl;


    // ASCII VALUE : a,b,c,...,z --> 97,98,99,....,122 (122-97+1)=26 chars
    // string s = "a";
    // cout<<s[0]+0;

    // ASCII VALUE : A,B,C,...,Z --> 65,66,67,....,90 (90-65+1)=26 chars
    // string s = "Z";
    // cout<<s[0]+0;

    string s1 = "nincompoop";
    string s2 = "e";
    cout<<s1.find(s2);

    
    return 0;
}