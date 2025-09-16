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
    scanf("%d", &n);

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - 1 - i])
            ans = gcd(ans, abs(a[i] - a[n - 1 - i]));
    }

    if (ans == 0)
        ans = -1;

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