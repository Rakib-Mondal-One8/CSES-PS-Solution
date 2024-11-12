#include <bits/stdc++.h>
using namespace std;
pair<int, int> path[1001][1001];
bool vis[1001][1001];
vector<pair<int, int>> moves = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};
int n, m;
int si, sj;
int ei, ej;
bool valid(int x, int y)
{
    return ((!vis[x][y]) && (x >= 0) && (x < n) && (y >= 0) && (y < m));
}
void bfs()
{
    queue<pair<int, int>> q;
    q.push({si, sj});

    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int xi = p.first;
        int yj = p.second;
        for (auto ed : moves)
        {
            int ci = xi + ed.first;
            int cj = yj + ed.second;

            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;

                path[ci][cj] = {ed.first, ed.second};
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if (c == '#')
                vis[i][j] = true;
            if (c == 'A')
            {
                si = i;
                sj = j;
            }
            if (c == 'B')
            {
                ei = i;
                ej = j;
            }
            path[i][j] = { -1, -1};
        }
    }
    bfs();
    if (vis[ei][ej])
    {
        cout << "YES" << endl;
        vector<pair<int, int>> ans;
        // pair<int, int> des = {ei, ej};
        while (ei != si || ej != sj)
        {
            ans.push_back(path[ei][ej]);
            ei -= ans.back().first;
            ej -= ans.back().second;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;

        for (auto i : ans)
        {
            if (i.first == 0 && i.second == -1)
                cout << "L";
            if (i.first == 0 && i.second == 1)
                cout << "R";
            if (i.first == 1 && i.second == 0)
                cout << "D";
            if (i.first == -1 && i.second == 0)
                cout << "U";
        }
    }
    else
        cout << "NO" << endl;

    return 0;
}