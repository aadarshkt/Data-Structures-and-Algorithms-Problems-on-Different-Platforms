#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> vis;
vector<vector<pair<int, int>>> parent;

bool shortestPathFound = false;
pair<int, int> shortestPath;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
pair<int, int> res;

void BFS(int n, int m)
{
    while (!q.empty())
    {
        pair<int, int> curr;
        curr = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            pair<int, int> next({curr.first + dx[k], curr.second + dy[k]});

            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)
            {
                if (matrix[curr.first][curr.second] == 'A')
                {
                    shortestPathFound = true;
                    res = curr;
                }
                continue;
            }

            if (matrix[curr.first][curr.second] == 'A')
            {
                if (matrix[next.first][next.second] == '.')
                {
                    matrix[next.first][next.second] = 'A';
                    parent[next.first][next.second] = curr;
                    q.push({next.first, next.second});
                }
            }

            if (matrix[curr.first][curr.second] == 'M')
            {
                if (matrix[next.first][next.second] != '#' && matrix[next.first][next.second] != 'M')
                {
                    matrix[next.first][next.second] = 'M';
                    q.push({next.first, next.second});
                }
            }
        }
    }
}

void trace(int sx, int sy, int ex, int ey)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    matrix.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, 0));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));

    vector<pair<int, int>> start;

    pair<int, int> I;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
            {
                I.first = i, I.second = j;
            }

            if (matrix[i][j] == 'M')
            {
                start.push_back(make_pair(i, j));
            }
        }
    }

    q.push(I);

    for (auto p : start)
    {
        q.push(p);
    }

    BFS(n, m);

    cout << res.first << " " << res.second;

    return 0;
}