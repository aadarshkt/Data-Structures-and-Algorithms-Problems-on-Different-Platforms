#include <bits/stdc++.h>
using namespace std;

//Popular Linked List question.


//O(n) time and O(1) space.

//Algorithm ;

/** 1-> inititate two variables slow and fast.
 * 2-> fast will move faster and distance between them will increase
 * 3-> Eventually they will meet because of loop.
 * 4-> now make slow = arr[0];
 * 5-> now move both slow and fast at same pace.
 * 6-> You will get the answer.
 * See the video of repeating elements to understand the concept
 * 7-> The video is good it clears all doubts.
 * 
 * **/


int findRepeatingEfficient(int arr[], int n)
{

    int slow = arr[0] + 1, fast = arr[0] + 1;

    do{
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;

    } while(slow != fast);

    slow = arr[0] + 1;

    while(slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }

    return fast - 1;

}
 
int main()
{
    //For zero we have to do everywhere plus one.

    int arr[] = {0, 2, 1, 3, 4, 5, 7, 4, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findRepeatingEfficient(arr, n);

    return 0;
}