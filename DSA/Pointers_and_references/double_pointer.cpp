#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 5;
    int *b = &a;
    cout<<b<<'\n';
    cout<<"address of b is "<<&b<<'\n';

    //How do we store address of b?
    //answer use double pointers, single pointers CANNOT hold addresses of pointers

    int **c = &b;
    cout<<"address stored by c is "<<c<<'\n';

    ///int *c = &b doesn't work?


    //How to store multidimensinal matrix using double pointer?
    //create a array of pointers and return the address of this array of pointer.
    //remember that new int[5] returns the address of first value of array of ints.
    //Just like that address of first pointer in array of pointers can reaturned in new int*[5]/
    //and address of pointer can only be stored in double 
    //why --> 
    //FOr eg int a = 5; int* b = &a, int** c = &b;
    // a -> type -> int -> address -> int*
    // b -> type -> int* --> address -> int**

    int rows = 5;

    int **d = new int*[rows]; //return address to first pointer of array of pointers.

    //d[i] -> a value in array of pointers, give that a new int array.
    //Now think int* a = new int[5]; a pointer a is pointer to the first value of int arrary.

    int cols = 5;

    for(int i=0;i<rows;i++){
        d[i] = new int[cols]; //d[i] is simply a int*
    }



    return 0;
}