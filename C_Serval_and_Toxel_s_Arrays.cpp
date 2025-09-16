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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    ll n , m;
    cin >> n >> m;

    vi a(n);
    vl apc(n + m + 1 , 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];

        apc[a[i]] = m + 1;
    }
    
    ll ans = 0;
    for (size_t i = 0; i < m; i++)
    {
        int p , v;
        cin >> p >> v;
        p --;

        apc[a[p]] -= m - i;
        a[p] = v;
        apc[v] += m - i;
    }
    
    int cnt = 0;
    for (auto x : apc)
    {
        if (x)
        {
            ans += ((m + 1) * m) / 2 - ((m + 1 - x) * (m - x)) / 2;
        }
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