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

int n, k;
ll a[1005], b[1005], mem[1005][1005];

ll dp(int i, int j)
{
    if (j == k)
        return 0;

    if (i == n)
        return -1e15;

    ll &ret = mem[i][j];

    if (ret != LLONG_MAX)
        return ret;

    ret = max(dp(i + 1, j + 1) + a[i] * b[j], dp(i + 1, j));

    return ret;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            mem[i][j] = LLONG_MAX;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];

    cout << dp(0, 0) << endl;
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