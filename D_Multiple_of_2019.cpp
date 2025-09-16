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
    string s;
    cin >> s;

    reverse(all(s));

    ll pot = 1, n = s.size(), ans = 0, sum = 0, mod = 2019;
    map<ll, ll> freq;
    freq[0] = 1;

    for (int i = 0; i < n; i++)
    {
        sum += (s[i] - '0') * pot % mod;
        sum %= mod;

        ans += freq[sum];

        freq[sum]++;
        pot *= 10;
        pot %= mod;
    }

    cout << ans << endl;
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