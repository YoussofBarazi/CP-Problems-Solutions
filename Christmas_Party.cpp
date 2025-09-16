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

vector<ll> calc_derangments(int n)
{
    vector<ll> derangments(n + 1);
    ll mod = 1e9 + 7;
    derangments[0] = 1, derangments[1] = 0;

    for (ll i = 2; i <= n; i++)
        derangments[i] = ((i - 1) * (derangments[i - 1] + derangments[i - 2]) % mod) % mod;

    return derangments;
}

void solve()
{
    int n;
    cin >> n;

    vector<ll> d = calc_derangments(n);

    cout << d[n] << endl;
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