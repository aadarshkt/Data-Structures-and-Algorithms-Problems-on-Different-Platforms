#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> visited;

void floodfill(int i, int j, int n, int &area, int &peri, bool flag)
{

    if (i < 0 || j < 0 || j >= n || i >= n || matrix[i][j] == '.')
    {
        if(flag) peri += 1;
        return;
    }

    if(visited[i][j] == 1) return;

    visited[i][j] = 1;

    area += 1;
    
    floodfill(i + 1, j, n, area, peri, true);
    floodfill(i, j + 1, n, area, peri, true);
    floodfill(i - 1, j, n, area, peri, true);
    floodfill(i, j - 1, n, area, peri, true);
}

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (name.length())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    matrix.resize(n, vector<char>(n, '0'));
    visited.resize(n, vector<bool>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int area = 0, ansArea = INT_MIN, peri = 0, ansPeri = INT_MAX;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j]) floodfill(i, j, n, area, peri, false);
            if(ansArea == area) ansPeri = min(ansPeri, peri);
            int tempArea = ansArea;
            ansArea = max(ansArea, area);
            if(tempArea != ansArea) ansPeri = peri;
            area = 0, peri = 0;
        }
    }

    cout << ansArea << " " << ansPeri << endl;

    return 0;
}