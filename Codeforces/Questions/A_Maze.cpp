#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n, m, k;
int need;
vector<string> grid;
vector<vector<int>> vis;

void dfs(int x, int y)
{
    if (need == 0) return;

    vis[x][y] = 1;
    need--;

    for (int d = 0; d < 4; d++)
    {
        if (need == 0) return;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < n &&
            ny >= 0 && ny < m &&
            !vis[nx][ny] &&
            grid[nx][ny] == '.')
        {
            dfs(nx, ny);
        }
    }
}

void solve()
{
    cin >> n >> m >> k;

    grid.resize(n);
    vis.assign(n, vector<int>(m, 0));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (char c : grid[i])
            if (c == '.') cnt++;
    }

    need = cnt - k;

    bool started = false;

    for (int i = 0; i < n && !started; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j);
                started = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
                cout << 'X';
            else
                cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}