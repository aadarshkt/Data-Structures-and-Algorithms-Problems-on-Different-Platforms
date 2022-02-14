#include <bits/stdc++.h>
using namespace std;

int count = 0;

int countDigits(int n)
{
   //Your code here
   if(n < 10){
       return 1;
   } else {
       return 1 + countDigits(n/10);
   }
 
   
  
    
}
 
int main(){
 
cout <<  countDigits(605);
 
 return 0;
}