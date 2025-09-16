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
    int n , t;
    cin >> n >> t;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0 , j = 0 , ans = 0;
    for (ll i = 0; i < n; i++)
    {
        j = max(i , j);
        while(j < n && a[j] + sum <= t) sum += a[j] , j ++;
        ans = max(ans , j - i);

        if (sum >= a[i]) sum -= a[i];
    }
    
    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}