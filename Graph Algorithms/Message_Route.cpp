#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
bool vis[N];
int par[N];
vector<int> v[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : v[p])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                par[child] = p;
            }
        }
    }
}
void path_print(int des)
{
    if (par[des] == -1)
    {
        cout << des << " ";
        return;
    }
    path_print(par[des]);
    cout << des << " ";
}
int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(par, -1, sizeof(par));
    bfs(1);

    if (vis[n] == true)
    {
        int cnt = 0;
        int x = n;
        while (x != -1)
        {
            cnt++;
            x = par[x];
        }
        cout << cnt << endl;
        path_print(n);
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
