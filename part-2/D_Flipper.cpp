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

    vi a(n), ans;
    vector<pair<int, int>> b;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(all(b));

    int i = b[n - 1].S;
    if (i == 0 && n > 1)
        i = b[n - 2].S;

    int x = i;
    for (size_t i = x; i < n; i++)
    {
        ans.pb(a[i]);
    }

    x = i - 1;
    while (x > 0 && a[x] < a[x - 1])
        x--;
    x++;
    for (size_t j = i - 1; j >= x; j--)
    {
        ans.pb(a[j]);
    }

    for (size_t i = 0; i < x; i++)
    {
        ans.pb(a[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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