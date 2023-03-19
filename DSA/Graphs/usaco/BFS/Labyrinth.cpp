#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

void BFS(int i, int j, int n, int m)
{
    visited[i][j] = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    q.push({i, j});

    while (q.empty() == false)
    {
        pair<int, int> curr;
        curr = q.front();
        q.pop();

        int x = curr.first, y = curr.second;

        for (int k = 0; k < 4; k++)
        {
            pair<int, int> next({x + dx[k], y + dy[k]});

            if (next.first >= n || next.second >= m || next.first < 0 || next.second < 0)
                continue;

            if (!visited[next.first][next.second])
            {
                if (matrix[next.first][next.second] != '#')
                {
                    q.push({next.first, next.second});
                    pair<int, int> p({x, y});
                    parent[next.first][next.second] = p;
                    visited[next.first][next.second] = 1;
                }
            }
        } 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    matrix.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, 0));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));
 
    int sx, sy, ex, ey;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
                sx = i, sy = j;
 
            if (matrix[i][j] == 'B')
                ex = i, ey = j;
        }
    }
 
    BFS(sx, sy, n, m);
 
    if (parent[ex][ey].first == -1)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    cout << "YES" << endl;
 
    int len = 0;
    vector<char> ans;
 
    pair<int, int> p({ex, ey});
 
    while (matrix[p.first][p.second] != 'A')
    {
        int childx = p.first, childy = p.second;
        p = parent[p.first][p.second];
        if (p.first > childx && p.second == childy)
            ans.push_back('U');
        if (p.first < childx && p.second == childy)
            ans.push_back('D');
        if (p.first == childx && p.second > childy)
            ans.push_back('L');
        if (p.first == childx && p.second < childy)
            ans.push_back('R');
        len++;
    }
 
    cout << len << endl;
 
    for (int i = (int)ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
 
    return 0;
}