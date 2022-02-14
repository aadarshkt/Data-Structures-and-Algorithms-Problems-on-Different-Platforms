#include <bits/stdc++.h>
using namespace std;

//O(n2) algorithm.

//Bubble sort in 4 lines.

/** for(int i=0; i<n-1; i++)
       for(int j=0; j<n-i-1; j++)
          if(arr[j] > arr[j+1])
             swap(arr[j], arr[j+1]);

             **/

/** Optimized bubble sort in 7 lines
 * 
 * for(int i=0; i<n-1; i++)
       for(int j=0; j<n-i-1; j++)
          if(arr[j] > arr[j+1])
             isVisited = true;
             swap(arr[j], arr[j+1]);
        if(isVisited == false)
           break;**/

           
void bubbleSort(int arr[], int n)
{
    //using j < n-1 because assume last element of array is to go to first position
    //then n-1 swaps is to be done.
    //One more optimization second loop j included.

    bool isVisited;
    int count = 0;
    for (int j = n; j > 1; j--)
    {
        isVisited = false;
        for (int i = 1; i < j; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i-1]);//Use swap function.

                isVisited = true;
                
            }
        }

        

        if(isVisited == false)
        break;


        count++;


    }

    

    cout << count << endl;

    //Imagine if only two elements are out of order 
    //many uneccessary loops must be running.
    //So to remove it we are doing isVisited part.

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    //Geeks for Geeks 

    
}

int main()
{

    int arr[] = {2, 10, 8, 7, 5, 35, 25, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    return 0;
}