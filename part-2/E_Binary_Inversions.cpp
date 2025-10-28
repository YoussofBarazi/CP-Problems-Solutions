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

    vl a(n) , b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    
    ll cnt = 0 , ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i]) ans += cnt;
        else cnt ++;
    }
    
    int i = 0;
    while(i < n && a[i])
    {
        i ++;
    }
    if (i == n) a[n - 1] = 0;
    else a[i] = 1;
    
    ll res = ans;
    cnt = 0 , ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i]) ans += cnt;
        else cnt ++;
    }
    
    i = n - 1;
    while (i >= 0 && !b[i])
    {
        i --;
    }
    if (i == -1) b[0] = 1;
    else b[i] = 0;
    res = max(res , ans);
    ans = cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i]) ans += cnt;
        else cnt ++;
    }
    
    cout << max (ans , res) << endl;
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