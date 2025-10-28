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
    int n , k;
    cin >> n >> k;

    vl cost1(2 * k + 10 , 0) , cost2(2 * k + 10 , 0);
    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vi exist;
    for (size_t i = 0; i < (n + 1) / 2; i++)
    {
        cost1[min(a[i] , a[n - i - 1]) + 1] ++;
        cost1[max(a[i] , a[n - i - 1]) + k + 1] --;
        exist.pb(a[i] + a[n - i - 1]);

        cost2[2] += 2;
        cost2[min(a[i] , a[n - i - 1]) + 1] -= 2;
        cost2[max(a[i] , a[n - i - 1]) + k + 1] += 2;
        cost2[2 * k + 1] -= 2;        
    }
    
    for (size_t i = 1; i <= 2 * k; i++)
    {
        cost1[i] += cost1[i - 1];
        cost2[i] += cost2[i - 1];
    }
    for (auto x : exist)
    {
        cost1[x] --;
    }
    
    ll ans = 1e9;
    for (size_t i = 2; i <= 2 * k; i++)
    {
        ans = min(ans , cost1[i] + cost2[i]);
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