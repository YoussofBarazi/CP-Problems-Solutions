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

    int distinct = n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i)
        {
            distinct = i;
            break;
        }
    }

    string ans(n, '.');
    for (int i = 1; i <= n; i++)
    {
        if (ans[i - 1] == '.')
            for (int j = i; j <= n; j += distinct)
                ans[j - 1] = char('a' + i - 1);
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