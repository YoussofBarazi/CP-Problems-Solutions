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
    int n;
    cin >> n;

    vi pre(n) , post(n) , a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int gcd = 0;
    for (size_t i = 0; i < n; i++)
    {
        gcd = __gcd(gcd , a[i]);
        pre[i] = gcd;
    }
    gcd = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        gcd = __gcd(gcd , a[i]);
        post[i] = gcd;
    }
    int ans = max(post[1] , pre[n - 2]);
    
    for (size_t i = 1; i < n - 1; i++)
    {
        ans = max(ans , __gcd(pre[i - 1] , post[i + 1]));
    }
    
    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
//    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}