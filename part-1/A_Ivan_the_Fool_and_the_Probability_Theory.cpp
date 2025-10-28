#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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
    ll n, m, mod = 1e9 + 7;
    cin >> n >> m;

    vector<ll> fib(max(n, m) + 1, 1);

    for (int i = 2; i < fib.size(); i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

    cout << (2ll * fib[n] + 2ll * fib[m] - 2) % mod << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}