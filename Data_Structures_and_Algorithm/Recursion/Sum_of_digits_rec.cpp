#include <bits/stdc++.h>
using namespace std;



int sumOfDigits(int n){

    if(n == 0){
        return 0;
    }
    

    return (n % 10 + sumOfDigits(n/10));

}

//Time Complexity is theta(No of digits)
//auxiliary space complexity is also theta(no of digits in the number)
 
int main(){
 
 cout << sumOfDigits(9989);
 
 return 0;
}