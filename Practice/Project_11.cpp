#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

//check if solution is possible.
bool check(vector<vector<int>> &mat){
    vector<int> a;
    for(int i=0; i<4;i++){
        for(int j=0;j<4;j++){
            a.push_back(mat[i][j]);
        }
    }

    int inv = 0;
    for (int i=0; i<16; ++i)
        if (a[i])
            for (int j=0; j<i; ++j)
                if (a[j] > a[i])
                    ++inv;
    for (int i=0; i<16; ++i)
        if (a[i] == 0)
            inv += 1 + i / 4;

    if(inv & 1)return false;
    return true;
}

int x[] = {0, 0, -1, 1};
int y[] = {1, -1, 0, 0};
set<vector<vector<int>>> st;

int 

void dfs(vector<vector<int>> &initial, vector<vector<int>> &final,int x, int y){

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v = {
		{1, 0, 3, 4},
        {6, 2, 11, 10},
        {5, 8, 7, 9},
        {14, 12, 15, 13}
	};

    vector<vector<int>> v = {
		{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
	};

    vector<vector<int>> final =
	{
		{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
	};

    if(!check(initial))cout<<"not solvable"<<'\n';
    else{

    }

    return 0;
}