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
    int n;
    cin >> n;

    vector<string> s(n);

    for (auto &x : s)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a1 = s[i][j], a2 = s[n - j - 1][i], a3 = s[n - i - 1][n - j - 1], a4 = s[j][n - 1 - i];

            int mx = max({a1, a2, a3, a4});

            ans += 4 * mx - a1 - a2 - a3 - a4;

            s[i][j] = mx;
            s[n - j - 1][i] = mx;
            s[n - i - 1][n - j - 1] = mx;
            s[j][n - 1 - i] = mx;
        }
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