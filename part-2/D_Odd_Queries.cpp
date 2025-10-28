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
    int n , q;
    cin >> n >> q;

    vl a(n) , sum (n , 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i] = (i == 0)? a[i] : a[i] + sum[i - 1];
    }
    
    for (size_t i = 0; i < q; i++)
    {
        ll l , r , k;
        cin >> l >> r >> k;
        l -- , r --;

        ll s = sum.back() - sum[r] , x = (r - l + 1);
        if (l > 0) s += sum[l - 1];
        
        x *= k;
        s += x;
        
        if (s % 2) cout << "YES" << endl;
        else cout << "NO" << endl;
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