#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

int n, s[N], e[N];

bool ok(int k)
{
    ll l = 0, r = 0;

    for (int i = 0; i < n; i++)
    {
        l -= k;
        r += k;
        
        l = max(l , 1ll * s[i]);
        r = min(r , 1ll * e[i]);

        if (l > r)
            return false;
    }

    return true;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> s[i] >> e[i];

    int l = 0, r = 1e9;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
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