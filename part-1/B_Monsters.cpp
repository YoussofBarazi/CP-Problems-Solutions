#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
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

bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.F != y.F)
        return x.F > y.F;
    return x.S < y.S;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % k)
            a.pb({x % k, i + 1});
        else
            cout << i + 1 << " ";
    }

    sort(all(a), cmp);

    for (auto x : a)
        cout << x.S << " ";
    cout << endl;
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