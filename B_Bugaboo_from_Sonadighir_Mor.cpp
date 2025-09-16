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

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> s;
    ll ans = 0;
    int l = 0, r = 1;

    s.insert(a[0]);

    while (l < n)
    {
        bool ok = false;
        while (r < n)
        {
            auto x = s.upper_bound(a[r]);
            auto y = x;

            ll next = INT_MAX, prev = INT_MIN;

            if (s.size() >= 1)
            {
                if (s.begin() == x)
                    next = *x;
                else if (x == s.end())
                    prev = *(--x);
                else
                    next = *y, prev = *(--x);
            }

            if (next - a[r] >= k && a[r] - prev >= k)
            {
                s.insert(a[r]);
                ok = true;
            }
            else
            {
                break;
            }
            r++;
        }

        ll size = s.size();
        if (ok)
            ans += 1ll * size * (size - 1) / 2;

        s.erase(a[l]);
        l++;
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