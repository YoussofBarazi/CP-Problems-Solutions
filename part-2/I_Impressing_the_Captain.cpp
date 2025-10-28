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
    int n, x;
    cin >> n >> x;

    map<int, ll> freq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        freq[x]++;
    }

    ll ans = 0;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (i * i == x)
                ans += freq[i] * (freq[i] - 1) / 2;
            else
                ans += freq[i] * freq[x / i];
        }
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