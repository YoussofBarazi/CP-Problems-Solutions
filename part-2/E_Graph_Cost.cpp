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

const int N = 1e6 + 9;

long long dp[N];

void precalc(int N)
{
    for (int i = 0; i < N; i++)
        dp[i] = 0;

    for (int i = N - 1; i >= 1; --i)
    {
        long long num_mul = 0;
        for (int j = i; j < N; j += i)
            num_mul++;

        dp[i] = (num_mul * (num_mul - 1)) / 2;

        for (int j = i + i; j < N; j += i)
            dp[i] -= dp[j];
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    precalc(n + 1);

    ll gcd = n;
    ll cost = 0;

    while (m > 0 && gcd > 1)
    {
        ll k = gcd - 1;

        cost += (min(dp[gcd], m) / k) * gcd;
        m -= (min(dp[gcd], m) / k) * k;

        gcd--;
    }

    if (m > 0)
        cout << -1 << endl;
    else
        cout << cost << endl;
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