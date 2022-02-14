#include <bits/stdc++.h>
using namespace std;
 

void fun1(int n){

    if(n == 0){
        return;
    }

    

    fun1(n/2);

    cout << (n % 2);

    

}
 
int main(){
 
 

 fun1(8);
 
 return 0;
}