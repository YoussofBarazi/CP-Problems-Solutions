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

ll mod = 1e9 + 7;
vector<ll> fact(N, 1);

void solve()
{
    int n;
    cin >> n;

    map<int, ll> freq;
    int res = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        res &= x;
        freq[x]++;
    }

    for (int i = 2; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    ll ans = (fact[n - 2] * freq[res] % mod) * (freq[res] - 1) % mod;

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