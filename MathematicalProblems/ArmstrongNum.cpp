// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
/*Def of Armstrong:
  if 153 = (1)^3 + (5)^3 + (3)^3 then Armstrong Num
  else Not Armstrong Num
*/
/* Armstrong Numbers: 0,1,153,370,371,407,1634,8208,9474*/

int main(){

    int n=153;
    
    int original=n;
    int sum=0;
    while(n>0){
        int lstdgt = n%10;
        sum += pow(lstdgt,3);
        cout<<"Sum="<<sum<<endl;
        n=n/10;
    }

    // cout<<"Sum = "<<sum<<endl;

    if(sum+1==original){
        cout<<"Armstrong Number"<<endl;
    }
    else{
        cout<<"NOT Armstrong Number"<<endl;
    }


    return 0;
}