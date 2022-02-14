#include <bits/stdc++.h>
using namespace std;

//Not tail recursive solution.



int factorial1(int n){

    if(n == 1){
        return 1;
    }

    return n * factorial1(n-1);

}

//Tail Recursive solution.

  int a = 1;

int factorial2(int n){

  

    if(n == 1 || n == 0){
        return 1;
    }

    a *= n * (n-1);

    factorial2(n-2);

return a;



}


 
int main(){
 
 cout << factorial1(4) << endl;

 cout << factorial2(4);


 
 return 0;
}