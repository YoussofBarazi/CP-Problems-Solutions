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

const int N = 200009;

int parent[N], idx[N];

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (idx[a] < idx[b])
            swap(a, b);
        parent[b] = a;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    iota(parent, parent + n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;

        if (s == "union")
            union_sets(u, v);
        else if (find_set(u) == find_set(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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