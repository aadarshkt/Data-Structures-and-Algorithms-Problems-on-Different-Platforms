#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 5;
    int &b = a;
    //but b = a creates new variable, copy of a's value but on different memory location
    cout<<b<<'\n';
    b = 10;
    cout<<a<<'\n';
    cout<<"b's address is "<<&b<<'\n';
    cout<<"a's address is "<<&a<<'\n';

    int* c = &a;
    cout<<"c's value is "<<c<<'\n';
    cout<<"value at of address stored in c "<<*c<<'\n';
    cout<<"a's adress "<<&a<<'\n';
    cout<<"c's address which is different because c is another variable. "<<&c<<'\n';

    //conclusion 
    //1. &b = a then b's address and b's value both become a's address
    //changin b's value changes a's values
    //2. *c = a, then a new variable c stores just only address of c

    //To test -> the references cannot be reassigned means it cannot made to alias different variable  but pointers can be reassigned.

    int* d = &a;
    cout<<"value of d is "<<*d<<'\n';
    cout<<"address of d is "<<d<<'\n';
    int e = 12;
    d = &e;
    cout<<"new value of d is "<<*d<<'\n';
    cout<<"address of d is "<<d<<'\n';

    int& f = a;
    cout<<"value of f is "<<f<<'\n';
    cout<<"the address of f is "<<&f<<'\n';
    f = e;
    cout<<"value of f is "<<f<<'\n';
    cout<<"the address of f is"<<&f<<'\n';

    return 0;
}