#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n){


    if(n==0) 
        return 0;
    else if(n==1)
        return 1;
    
    return Fibonacci(n-1) + Fibonacci(n-2);
}
 
int main(){
 
 cout << Fibonacci(5);
 
 return 0;
}