#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int par(int i){
	return (i - 1)/2;
}

void shift_up(int ind,vector<int> &ans){
	int curr = ind;

	while(curr != 0 && ans[par(curr)] < ans[curr]){
		swap(ans[par(curr)],ans[curr]);
		curr = par(curr);
	}
}

void insert(int val,vector<int> &ans){
	int n = ans.size(); //last index after inserting
	ans.push_back(val);

	shift_up(n,ans);
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	vector<int> ans;
	for(int i=0;i<n;i++){
		insert(arr[i],ans);
	}
	return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}