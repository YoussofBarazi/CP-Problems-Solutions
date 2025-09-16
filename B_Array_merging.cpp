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

    vi freq_a(2 * n + 7, 0), freq_b(2 * n + 7, 0), a(n + 1), b(n + 1);
    a[n] = b[n] = 0;

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
            cnt++;
        else
            cnt = 0;

        freq_a[a[i]] = max(freq_a[a[i]], cnt + 1);
    }

    for (size_t i = 0; i < n; i++)
    {
        if (b[i] == b[i + 1])
            cnt++;
        else
            cnt = 0;

        freq_b[b[i]] = max(freq_b[b[i]], cnt + 1);
    }

    int ans = 0;
    for (size_t i = 0; i < 2 * n + 7; i++)
    {
        ans = max(ans, freq_a[i] + freq_b[i]);
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