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
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> damaged(n + 1, 0);
    while (b--)
    {
        int x;
        cin >> x;

        damaged[x]++;
    }

    for (int i = 1; i <= n; i++)
        damaged[i] += damaged[i - 1];

    int ans = 1e8;
    for (int i = k; i <= n; i++)
        ans = min(ans, damaged[i] - damaged[i - k]);

    cout << ans << endl;
}

int main()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}