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

const int N = 1e8 + 1;

int mem[N];

int n, D, E;

int dp(int i)
{
    if (i - min(D, E * 5) < 0)
        return i;

    if (mem[i] != -1)
        return mem[i];

    int ans1 = 1e9, ans2 = 1e9;
    if (i - D >= 0)
        ans1 = dp(i - D);
    if (i - E * 5 >= 0)
        ans2 = dp(i - E * 5);

    mem[i] = min(ans1, ans2);

    return mem[i];
}

void solve()
{
    cin >> n >> D >> E;

    for (int i = 0; i <= n; i++)
        mem[i] = -1;

    cout << dp(n) << endl;
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