#include <bits/stdc++.h>
using namespace std;

void printAllSubsequence(string input, string output)
{

    if(input.empty())
    {
        cout << output << endl;
        return;
    }

    ///You have two options either you pick or kick // Keep doing this and you will find many subsequence.(2^n);
    
    printAllSubsequence(input.substr(1), output + input[0]); //Pick

    printAllSubsequence(input.substr(1), output); //Not pick
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input = "abcd";

    string output = "";

    printAllSubsequence(input, output);

    return 0;
}