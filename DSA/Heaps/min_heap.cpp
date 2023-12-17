#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

class minHeap {
public:
    int heap_size = 0,size = 0;
    int *arr;
    // Constructor for the class.
    minHeap(int sz) {
        // Write your code here.
        heap_size = 0;
        arr = new int[sz];
        size = sz;
    }

    int par(int i){
        return (i - 1) / 2;
    }

    int lchild(int i){
        return (2 * i + 1);
    }

    int rchild(int i){
        return (2 * i + 2);
    }

    void shift_up(int i){
        while(i!= 0 && arr[par(i)]>arr[i]){
            swap(arr[par(i)],arr[i]);
            i = par(i);
        }
    }

    void shift_down(int i){
        int smallest = i;

        int lc = lchild(i),rc = rchild(i);

        if(rc<heap_size && arr[rc]<arr[i]){
            smallest = rc;
        }

        if(lc<heap_size && arr[smallest]>arr[lc]){
            smallest = lc;
        }

        if(smallest == i)return;

        swap(arr[i],arr[smallest]);
        shift_down(smallest);
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
        int mn_ele = arr[0];
        if(heap_size == 0)return -1;
        if(heap_size == 1){
            heap_size--;
            return arr[heap_size];
        }

        swap(arr[0],arr[heap_size-1]);

        heap_size--;

        shift_down(0);

        return mn_ele;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
        if(ind>=heap_size)return;
        if(heap_size == 0)return;
        if(heap_size == 1){
            heap_size--;
            return;
        }
        arr[ind] = INT_MIN;
        shift_up(ind);
        extractMinElement();
    }


    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        if(heap_size == size)return;
        arr[heap_size++] = val;

        shift_up(heap_size-1);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minHeap pq = minHeap(10);

    pq.insert(5);
    pq.insert(15);
    pq.insert(43);

    pq.deleteElement(2);

    cout<<pq.extractMinElement()<<'\n';

    return 0;
}