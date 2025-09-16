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
    ll sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }    
    
    if (k == 1)
    {
        cout << sum << endl;
        return;
    }
    else n --;

    int i = 0 , c = k;
    ll ans = a.back();
    while (i < n && c > 0)
    {
        ll s = 0;
        while (i < n && s < (sum + k - 1) / k)
        {
            s += a[i];
            i ++;
        }

        c --;
        ans = max(ans , s);
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