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

    vector<int> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(all(a)), sort(all(b));

    int j = 0, mx = 0, cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (j < n && a[i] >= b[j])
        {
            mx = max(mx, b[j]);
            j++;
            cnt++;
        }

        j++;

        if (j >= n)
        {
            break;
        }
    }

    while (j < n)
        mx = max(mx, b[j++]), cnt++;

    ll ans = 0;

    if (mx <= m)
    {
        ans += 1ll * (cnt - 1) * (mx - 1);
        ans += 1ll * cnt * (m - mx + 1);
    }
    else
    {
        ans += 1ll * (cnt - 1) * (m);
    }

    cout << ans << endl;
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