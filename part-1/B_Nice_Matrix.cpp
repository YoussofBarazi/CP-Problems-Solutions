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
    int n , m;
    cin >> n >> m;

    vl a[n];
    for (size_t i = 0; i < n; i++)
    {
        a[i].resize(m);
        for (size_t j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    ll ans = 0 , sum = 0;
    for (size_t i = 0; i < (n + 1) / 2; i++)
    {
        for (size_t j = 0; j < (m + 1) / 2; j++)
        {
            vl x;
            x.pb(a[i][j]);

            if (n - i - 1 > i) x.pb(a[n - i - 1][j]);
            if (m - j - 1 > j) x.pb(a[i][m - j - 1]);
            if (m - j - 1 > j && n - i - 1 > i) x.pb(a[n - i - 1][m - j - 1]);  

            Sort(x);

            ll y = x[max(int (x.size()) / 2 - 1, 0)];
            
            ans += abs (a[i][j] - y);
            if (n - i - 1 > i) ans += abs(a[n - i - 1][j] - y);
            if (m - j - 1 > j) ans += abs(a[i][m - j - 1] - y);
            if (m - j - 1 > j && n - i - 1 > i) ans += abs(a[n - i - 1][m - j - 1] - y);  
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