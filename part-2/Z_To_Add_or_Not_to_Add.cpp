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
    int n , k;
    cin >> n >> k;

    vl a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Sort(a);

    ll j = 0 , mn = a[j] , ans = 1 , op = 0;
    for (size_t i = 1; i < n; i++)
    {
        op += (a[i] - a[i - 1]) * (i - j);
        
        while (j < i && op > k) op -= a[i] - a[j] , j ++;

        if (ans < i - j + 1 && op <= k)
        {
            ans = i - j + 1;
            mn = a[i];
        }
    }
    
    cout << ans << " " << mn << endl;
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