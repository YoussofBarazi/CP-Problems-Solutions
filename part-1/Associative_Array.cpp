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

void solve()
{
    int q;
    cin >> q;

    map<ll, int> m;
    vector<tuple<int, ll, ll>> query;

    for (int i = 0; i < q; i++)
    {
        ll t, k, v = 0;
        cin >> t >> k;

        if (t == 0)
            cin >> v;

        query.pb({t, k, v});
        m[k];
    }

    int ind = 0;
    for (auto &x : m)
    {
        x.S = ind++;
    }

    vector<ll> a(ind + 1, 0);
    for (auto q : query)
    {
        ll t = get<0>(q), k = get<1>(q), v = get<2>(q);

        if (t == 0)
            a[m[k]] = v;
        else
            cout << a[m[k]] << endl;
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