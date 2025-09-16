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
    int n , q;
    cin >> n >> q;

    vl a(n) , s(n + 1 , 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (size_t i = 0; i < n; i++)
    {
        if (i > 1 && a[i - 2] >= a[i - 1] && a[i - 1] >= a[i])
        {
            continue;
        }
        s[i + 1] ++;
    }

    for (size_t i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
    }
    
    for (size_t i = 0; i < q; i++)
    {
        int l , r;
        cin >> l >> r;
        l --;
        ll ans = s[r] - s[l];
        if (l >= 2 && a[l - 2] >= a[l - 1] && a[l - 1] >= a[l]) ans ++;
        if (l >= 1 && a[l - 1] >= a[l] && a[l] >= a[l + 1]) ans ++;
        if(r - l == 1) ans = 1;
        if(r - l == 2) ans = 2;

        cout << ans << endl;
    }
    
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