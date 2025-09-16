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

const int N = 2000009;

ll sum[1500][1500];
ll ans[N];

void calc()
{
    ll cur = 1;
    for (int i = 1; i < 1500; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            sum[j][i - j] = sum[j - 1][i - j] + sum[j][i - j - 1] - sum[j - 1][i - j - 1] + cur * cur;
            ans[cur] = sum[j][i - j];
            cur++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    cout << ans[n] << endl;
}

int main()
{
    IOS;
    calc();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}