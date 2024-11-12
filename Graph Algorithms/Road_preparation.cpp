#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll parent[100005];
ll sz[100005];
void make(int n)
{
    parent[n] = n;
    sz[n] = 1;
}
int find(int nde)
{
    if (parent[nde] == nde)
        return nde;
    return parent[nde] = find(parent[nde]);
}
void union_sz(int nde1, int nde2)
{
    int a = find(nde1);
    int b = find(nde2);

    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edlist;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edlist.push_back(Edge(u, v, w));
    }
    sort(edlist.begin(), edlist.end(), cmp);
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    ll cost = 0;
    for (auto ed : edlist)
    {
        int a = find(ed.u);
        int b = find(ed.v);

        if (a != b)
        {
            union_sz(a, b);
            cost += ed.w;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
        cout << cost << endl;
    return 0;
}
