#include <bits/stdc++.h>
using namespace std;

//Very complex and hard using arrays.

int getSecondMax(vector<int> v, int n){


     int a = *max_element(v.begin(), v.end());

 

     auto it = find(v.begin(), v.end(), a);

     int index = it - v.begin();

     v.erase(it);

     int res = *max_element(v.begin(), v.end());



  

    
    
}
 
int main(){
 
 vector<int> v = {1, 2, 3, 4, 5, 12, 45, 87};

 int n = v.size();
 
 cout << getSecondMax(v, n);
 
 return 0;
}