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

const int N = 300009;

ll fact[N] = {1};

ll mod = 998244353;

int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> a(n + 1, {0, 0});
    map<int, int> freq1, freq2;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F >> a[i].S;

        freq1[a[i].F]++, freq2[a[i].S]++;
    }

    ll cnt1 = 1, cnt2 = 1;

    for (int i = 0; i <= n; i++)
    {
        cnt1 *= fact[freq1[i]];
        cnt1 %= mod;

        cnt2 *= fact[freq2[i]];
        cnt2 %= mod;
    }

    sort(all(a));

    ll cnt12 = 1;

    freq2.clear();

    for (int i = 1; i <= n; i++)
    {
        freq1[a[i].F]--;
        freq2[a[i].S]++;

        if (freq1[a[i].F] == 0)
        {
            for (auto x : freq2)
                cnt12 = cnt12 * fact[x.S] % mod;

            freq2.clear();
        }

        if (a[i].S < a[i - 1].S)
            cnt12 = 0;
    }

    ll ans = fact[n] - (cnt1 + cnt2 - cnt12) + 2 * mod;

    cout << ans % mod << endl;
}

int main()
{
    IOS;

    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}