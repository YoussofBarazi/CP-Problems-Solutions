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
    int n;
    cin >> n;

    vi ans;

    for (int i = 1; i < n; i++)
    {
        if (gcd(n, i) == 1)
            ans.pb(i);
    }

    int size = 0;
    ll x = 1;

    for (size_t i = 0; i < ans.size(); i++)
    {
        x *= ans[i];
        x %= n;

        if (x == 1)
            size = i + 1;
    }

    cout << size << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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