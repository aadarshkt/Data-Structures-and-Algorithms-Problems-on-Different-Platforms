#include <bits/stdc++.h>
using namespace std;

int sum(int n){


    if(n == 0){
        return 0;
    }

    return (n + sum(n-1));



}

//Time complexitity is theta(n); for every recursion you have to do constant amount of work.
// Space complexitity is theta(n); call stack has height (n+1); Auxiliary space.
 
int main(){
 
 cout << sum(5);

 
 return 0;
}