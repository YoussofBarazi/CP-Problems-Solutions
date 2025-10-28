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
    int n;
    cin >> n;

    vector <pi> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F;
        a[i].S = i + 1;
    }
    Sort(a);
    vi ans;
    
    for (size_t i = 1; i < n; i++)
    {
        int mn = a[i - 1].F;
        while (a[i].F % mn)
        {
            ans.pb(a[i].S) , ans.pb(mn - a[i].F % mn);
            a[i].F += mn - a[i].F % mn;
        }
    }
    
    cout << ans.size() / 2 << endl;
    for (size_t i = 0; i < ans.size(); i += 2)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
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