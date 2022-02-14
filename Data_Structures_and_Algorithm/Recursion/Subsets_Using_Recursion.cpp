#include <bits/stdc++.h>
using namespace std;


int i = 0;
int a = 0;

void generateSubStrings(string &s, string curr = "", int i=0){




    if(i == s.length()){
        cout << curr << endl;
        return;
    }

    
 
    generateSubStrings(s, curr, i+1);

    generateSubStrings(s, curr + s[i], i+1);

   
   



} 
 
int main(){
 
 string s1 = "ABC";

 generateSubStrings(s1);
 
 return 0;
}