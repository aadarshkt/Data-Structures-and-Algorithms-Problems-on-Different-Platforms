#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void printAllPermutation(string s, int i = 0, string curr = "", int index = -1)
{

    if (counter == 6)
    {
        return;
    }

    if (index == 2)
    {
        cout << curr << endl;
        counter++;
        curr = "";
    }

    if (i > 2)
    {
        i = i - s.length()+1;
        index = -1;
    }

    
    printAllPermutation(s, i+1, curr + s[i], index+1);

}

int main()
{

    string s1 = "ABC";

    printAllPermutation(s1);

    return 0;
}