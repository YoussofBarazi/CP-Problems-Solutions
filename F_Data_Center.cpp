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

    int ans = 2 + n * 2;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = min(2 * i + 2 * (n / i), ans);
        }
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    //    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}