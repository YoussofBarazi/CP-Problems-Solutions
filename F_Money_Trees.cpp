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
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1, 1e9 + 7), h(n + 1, 1e9 + 7);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    ll s = 0;
    int l = 0, r = 0, ans = 0;

    while (l < n)
    {
        if (l == r || h[r - 1] % h[r] == 0)
            s += a[r], r++;
        else
            s = a[r], l = r, r++;

        while (s > k)
            s -= a[l], l++;

        ans = max(ans, r - l);
    }

    cout << ans << endl;
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