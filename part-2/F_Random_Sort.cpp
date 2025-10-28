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

vector<ll> fact(1001, 1);
int mod = 7901;

void get()
{
    for (int i = 1; i <= 1000; i++)
        fact[i] = fact[i - 1] * i % mod;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> freq(1001, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        freq[x]++;
    }

    ll ans = 1;
    for (int i = 0; i <= 1000; i++)
    {
        ans *= fact[freq[i]];
        ans %= mod;
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