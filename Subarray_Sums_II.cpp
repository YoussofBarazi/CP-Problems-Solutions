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
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    vector<ll> sum(n + 1, 0);
    map<ll, int> freq;
    ll ans = 0;
    freq[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        sum[i + 1] = sum[i] + a[i];
        ans += freq[sum[i + 1] - x];

        freq[sum[i + 1]]++;
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