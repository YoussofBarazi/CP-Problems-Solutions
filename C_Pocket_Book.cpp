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
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (auto &x : s)
        cin >> x;

    ll ans = 1;
    for (int j = 0; j < m; j++)
    {
        set<char> unique;
        for (int i = 0; i < n; i++)
        {
            unique.insert(s[i][j]);
        }

        ans *= 1ll * unique.size();
        ans %= int(1e9 + 7);
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