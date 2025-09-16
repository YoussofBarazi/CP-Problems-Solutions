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
    int n;
    cin >> n;

    vector<ll> s(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    vector<int> f(7, 1e8);
    f[0] = 0;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, i - f[s[i] % 7]);
        f[s[i] % 7] = min(f[s[i] % 7], i);
    }

    cout << ans << endl;
}

int main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}