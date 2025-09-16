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

int a[N];
int mem[N][3];
int n;

int dp(int i, int s)
{
    if (i > n)
        return 1e9;
    if (i == n)
        return 0;

    int &ret = mem[i][s];
    if (ret != -1)
        return ret;

    ret = dp(i + a[i] + 1, 0);
    ret = min(ret, dp(i + 1, 1) + 1);

    return ret;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        mem[i][0] = mem[i][1] = -1;

    cout << dp(0, 0) << endl;
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