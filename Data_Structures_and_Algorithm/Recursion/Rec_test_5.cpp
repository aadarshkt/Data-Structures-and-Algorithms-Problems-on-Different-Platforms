#include <bits/stdc++.h>
using namespace std;

void printUptoN(int n){

    if(n == 0){
        return;
    }

    cout << n << " ";

    printUptoN(n-1);

}

void printtoN(int n){

    if(n == 0){
        return;
    }

    printtoN(n-1);

    cout << n << " ";



}

//Time Complexity for above function is theta(n);
// Auxiliary space for the algorithm is omega(n);because it is the best case.. for each recursion call we can have more auxiliary space involved.
 
int main(){
 
 printUptoN(5);

 cout << endl;

 printtoN(5);

 cout << endl;
 
 return 0;
}