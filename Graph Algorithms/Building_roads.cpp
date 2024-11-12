#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
vector<int> v[N];
bool vis[N];
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n] = true;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : v[p])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
            }
        }
    }
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
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    vector<int> path;
    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            cnt++;
            path.push_back(i);
            bfs(i);
        }
    }
    cout << cnt - 1 << endl;

    // for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j < path.size(); j++)
        {
            cout << path[j - 1] << " " << path[j];
            cout << endl;
        }

    }
    return 0;
}
