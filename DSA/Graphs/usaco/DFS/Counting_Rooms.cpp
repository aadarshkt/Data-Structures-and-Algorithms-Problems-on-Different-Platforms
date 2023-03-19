#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> visited;

bool floodfill(int i, int j, int n, int m)
{
    if (i >= n || j >= m || i < 0 || j < 0 || matrix[i][j] == '#' || visited[i][j] == 1)
        return false;

    visited[i][j] = 1;

    floodfill(i, j + 1, n, m);
    floodfill(i + 1, j, n, m);
    floodfill(i - 1, j, n, m);
    floodfill(i, j - 1, n, m);

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    matrix.resize(n, vector<char>(m, '0'));
    visited.resize(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                flag = floodfill(i, j, n, m);
                if(flag) ans += 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}