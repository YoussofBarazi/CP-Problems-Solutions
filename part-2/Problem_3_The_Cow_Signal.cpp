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
    int n, m, k;
    cin >> m >> n >> k;

    vector<string> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];

    for (int i = 0; i < m; i++)
    {
        string ans;
        for (int j = 0; j < n; j++)
        {
            ans += string(k, s[i][j]);
        }

        for (int i = 0; i < k; i++)
            cout << ans << endl;
    }
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