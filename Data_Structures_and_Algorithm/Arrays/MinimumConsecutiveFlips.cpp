#include <bits/stdc++.h>
using namespace std;

int main()
{
    //My own solution.Creating own solution creates love for coding.

    int arr[] = {0, 0, 1,1, 1,1, 0, 0, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    // int partition1 = 0;

    // int partition0 = 0;

    // bool green = true;

    // bool red = true;

    // int visited1 = 0;

    // int visited0 = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 1)
    //     {

    //         green = true;
    //         red = false;

    //         visited1++;
    //     }
    //     else
    //     {

    //         green = false;
    //         red = true;

    //         visited0++;
    //     }

    //     if (green == true && red == false)
    //     {
    //         visited0 = 0;
    //         if (visited1 < 2)
    //         {
    //             partition1++;
    //         }
    //     }
    //     else if (green == false && red == true)
    //     {
    //         visited1 = 0;
    //         if (visited0 < 2)
    //         {
    //             partition0++;
    //         }
    //     }
    // }

    // cout << partition1 << " " << partition0 << endl;

    // for(int i=0; i<n; i++){
    //     if(partition1 < partition0){
    //         if(arr[i] == 1){
    //             cout << "From " << i << " to" << endl;
    //         }
    //     } else if(partition1  > partition0){
    //         if(arr[i] == 0)
    //            cout << "From " << i << " to" << endl;
    //     } else {
    //         cout << "Flip any group." << endl;
    //     }
    // }

    //Simpler Solution just flip the second group in overall array.
    //Only the second causes minimum no of flips.

    // int second = 0;

    // for (int i = 1; i < n; i++)
    // {

    //     if (arr[i] != arr[0])
    //     {
    //         second = arr[i];
    //         break;
    //     }
    // }

    // bool isVisited = false;

    // for (int i = 0; i < n; i++)
    // {
         

    //     if (isVisited == false)
    //     {
    //         if (arr[i] == second)
    //         {
    //             cout << "From " << i << " to ";
    //             isVisited = true;
    //         }
    //     }
    //     if (isVisited == true)
    //     {

    //         if (arr[i+1] != second)
    //         {
    //             cout << i<< endl;
    //             isVisited = false;
    //         }
    //     }
    // }

    //Crush it only one loop.

    for(int i=1; i<n; i++){       

        if(arr[i] != arr[i-1]){

            if(arr[i] != arr[0]){
                cout << "From " << i << " to ";
            } else {
                cout << i-1 << endl;
            }


             
          }

        } 


        if(arr[n-1] != arr[0]){
              cout << n-1 << endl; 

         

    }


    


    return 0;
}