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

int parent[N], Size[N];
int w;

int get(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

bool join(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    if (Size[a] < Size[b])
        swap(a, b);

    parent[b] = a;

    Size[a] += Size[b];

    return true;
}

int c = 1;

void solve()
{
    int n, u, v, r;
    cin >> n >> r >> w >> u >> v;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        Size[i] = 1;
    }

    vector<pi> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;

    vector<pair<pair<double, int>, pi>> edge;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dist = hypot((a[i].F - a[j].F), (a[i].S - a[j].S));

            bool state = dist - r > 0;

            if (dist - r > 0)
                dist *= v;
            else
                dist *= u;

            edge.push_back({{dist, state}, {i + 1, j + 1}});
        }
    }

    sort(all(edge));

    double A = 0, B = 0;
    int cnt = n;
    for (auto e : edge)
    {
        if (join(e.S.F, e.S.S))
        {
            if (e.F.S)
                B += e.F.F;
            else
                A += e.F.F;

            cnt--;
        }

        if (cnt == w)
            break;
    }

    cout << fixed << setprecision(3);
    cout << "Caso #" << c++ << ": " << A << " " << B << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}