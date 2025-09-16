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

const int N = 1e6 + 1;

long long sum[N];

void precalc()
{
    for (int i = 2; i < N; ++i)
    {
        for (int j = i + i; j < N; j += i)
        {
            sum[j] += 1ll * i;
        }
    }

    for (int i = 2; i < N; i++)
        sum[i]++;
}

void solve()
{
    int n;
    cin >> n;

    string ans = "abundant";
    if (sum[n] < n)
        ans = "deficient";
    else if (sum[n] == n)
        ans = "perfect";

    cout << ans << endl;
}

int main()
{
    IOS;

    precalc();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}