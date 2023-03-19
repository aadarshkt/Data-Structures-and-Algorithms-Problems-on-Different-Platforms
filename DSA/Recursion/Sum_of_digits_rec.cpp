#include <bits/stdc++.h>
using namespace std;

//Thinking this way -> we get a last digit and add it to last digit of a number that is one digit less than the previous number.

// Time Complexity is theta(No of digits)
// auxiliary space complexity is also theta(no of digits in the number)

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + sumOfDigits(n / 10);
}

int a = 0;

void numberOfDigits(int n)
{
    if(n == 0)
    {
        cout << a << endl;
        return;
    }

    a += 1;

    numberOfDigits(n/10);

}

int main()
{

    numberOfDigits(9987);
    cout << sumOfDigits(9987);

    return 0;
}