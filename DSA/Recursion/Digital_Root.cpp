#include <bits/stdc++.h>
using namespace std;

int digitalRoot(int n)
{
    //Your code here
    
     int sum = 0;
    
    if(n/10 == 0){
        return n;
    }
    
    while(n > 0){
        
        sum += n % 10;
    
    n /= 10;
        
    }
   
    
    
    
    digitalRoot(sum);
    
    
    
    
}
 
int main(){
 
  cout << digitalRoot(999);
 
 return 0;
}