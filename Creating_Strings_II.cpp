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

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

void solve()
{
    string s;
    cin >> s;

    map<char, ll> freq;

    for (auto x : s)
        freq[x]++;

    vector<ll> fact(s.size() + 1, 1);
    ll mod = 1e9 + 7;

    for (int i = 1; i <= s.size(); i++)
        fact[i] = fact[i - 1] * i, fact[i] %= mod;

    ll ans = fact[s.size()];
    for (auto x : freq)
    {
        ans *= inv(fact[x.S]);
        ans %= mod;
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}