#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//shift_up and shift_down are main function.
//shifting up requires only one comparision
//whereas shifting_down requires two comparsion, to get largest element to top.

struct MaxHeap {
    int heap_size; //current size of array
    int size; // total size of array possible.
    int *arr;

    MaxHeap(int sz){
        size = sz;
        heap_size = 0;
        arr = new int[sz];
    }

    int par(int i){
        return (i - 1)/2;
    }

    int lchild(int i){
        return (2 * i + 1);
    }

    int rchild(int i){
        return (2 * i + 2);
    }

    int getMax(){
        return arr[0];
    }

    int getSize(){
        return heap_size;
    }

    //swapping helper function to go up for greater value.
    void shift_up(int i){
        int curr = i;

        //keep swapping with parent if parent is less and child is more.
        while(curr != 0 && arr[par(curr)]<arr[curr]){
            swap(arr[par(curr)], arr[curr]);
            curr = par(curr);
        }
    }


    //helper function
    //swapping smaller values all the way to down.
    void shift_down(int i){
        int largest = i;
        int lc = lchild(i), rc = rchild(i);

        if(rc<heap_size && arr[i]<arr[rc]){
            largest = rc;
        }

        if(lc<heap_size && arr[largest]<arr[lc]){
            largest = lc;
        }

        if(largest == i)return;

        swap(arr[i],arr[largest]);
        shift_down(largest);
    }

    void insert(int x){
        if(size == heap_size)return;

        arr[heap_size++] = x;

        int curr = heap_size - 1;

        shift_up(curr);   
    }

    void remove_max(){
        if(heap_size == 0)return;
        if(heap_size == 1){
            heap_size--;
            arr = new int[size];
            return;
        }

        swap(arr[0],arr[heap_size-1]);
        heap_size--;

        shift_down(0);
    }

    //increase val at index and decrease val at index.

    void increase_val(int i,int new_val){
        arr[i] = new_val;
        shift_up(i);
    }

    void decrease_val(int i,int new_val){
        arr[i] = new_val;
        shift_down(i);
    }

    //delete val
    void delete_val(int i){
        arr[i] = INT_MAX;
        shift_up(i);
        remove_max();
    }

};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MaxHeap pq = MaxHeap(10);

    pq.insert(30);
    pq.insert(10);
    pq.insert(100);

    cout<<pq.getMax()<<'\n';

    pq.remove_max();

    cout<<pq.getMax()<<'\n';

    pq.increase_val(pq.getSize()-1,100);

    cout<<pq.getMax()<<'\n';
    

    return 0;
}