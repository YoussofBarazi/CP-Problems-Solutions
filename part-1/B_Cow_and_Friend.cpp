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
    ll n , x;
    cin >> n >> x;

    vl a(n);
    ll sum = 0;
    ll ans = oo;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];

        if (sum == x)
            ans = min (ans , i + 1);

        if (sum > x)
            ans = min (ans , i + 2);

        if (x % sum == 0) 
            ans = min (ans , (x / sum) * (i + 1));
        
        if (x % a[i] == 0) 
            ans = min (ans , x / a[i]);
        else if (a[i] > x)
            ans = min (ans , 1ll * 2);
        else 
            ans = min (ans , x / a[i] + 1);
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