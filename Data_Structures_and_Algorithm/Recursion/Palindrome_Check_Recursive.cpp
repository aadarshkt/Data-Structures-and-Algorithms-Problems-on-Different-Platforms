#include <bits/stdc++.h>
using namespace std;

// 1. start from last and first. Then check first and last if they are equal move to next.If string is completely traversed return true.
// If at any point the string element is not equal return false.

//subproblem is checking palindrome for one less string from both sides.

// Time complexity of the alogrithm is O(n/2) which is O(n);
// Space complexity of the algorithm is worst case theta(n) recursive call we drop 1/2;

void isPalindrome(string s, int startingPoint, int endingPoint)
{
    if (startingPoint >= endingPoint)
    {
        cout << "Yes" << endl;
        return;
    }

    if (s[startingPoint] == s[endingPoint])
    {
        isPalindrome(s, startingPoint + 1, endingPoint - 1);
    }
    else
    {
        cout << "No" << endl;
        return;
    }
}



int main()
{

    string s1 = "12";

    int a = s1.length();

    isPalindrome(s1, 0, a - 1);

    return 0;
}