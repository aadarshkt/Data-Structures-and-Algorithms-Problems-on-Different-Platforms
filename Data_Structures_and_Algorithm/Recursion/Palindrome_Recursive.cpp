#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int startingPoint, int endingPoint){


    if(startingPoint >= endingPoint ){
        return true;
    }

    //If first is true then only second will run .

 
    return (s[startingPoint] == s[endingPoint] && isPalindrome(s, startingPoint+1, endingPoint-1));

}

//Time complexity of the alogrithm is O(n/2) which is O(n);
//Space complexity of the algorithm is worst case theta(n) recursive call we drop 1/2;
 
int main(){

    string s1 = "123321";

    int a = s1.length();
 
 cout << isPalindrome(s1, 0, a-1) << endl;
 
 return 0;
}