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

int MOD = 1e9 + 7;

const int N = 200009;

vi factorial(1e5 + 1);

void get ()
{
    factorial[0] = 1;
    for (size_t i = 1; i < 1e5 + 1; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

void solve()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        ans += ((n - i) * 2) * factorial[n];
        ans = ans % MOD; 
    }
    
    cout << ans << endl;
}

int main()
{
    IOS;
    get();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}