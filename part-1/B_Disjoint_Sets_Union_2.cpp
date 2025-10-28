#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 300009;

int parent[N], Size[N], minimal[N], maximal[N];

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);

        parent[b] = a;

        minimal[a] = min(minimal[a], minimal[b]);
        maximal[a] = max(maximal[a], maximal[b]);

        Size[a] += Size[b];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        Size[i] = 1;
        minimal[i] = i;
        maximal[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        int u, v;
        cin >> s >> u;

        if (s == "union")
        {
            cin >> v;
            union_sets(u, v);
        }
        else
        {
            int p = find_set(u);

            cout << minimal[p] << " " << maximal[p] << " " << Size[p] << endl;
        }
    }
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}