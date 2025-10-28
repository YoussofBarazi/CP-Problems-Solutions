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

    vector<vector<string>> s(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        string x;
        cin >> x >> m;

        s[i].resize(m);

        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cnt = 0;

            for (int x = 0; x < s[i].size(); x++)
            {
                for (int y = 0; y < s[j].size(); y++)
                {
                    if (s[j][y] == s[i][x])
                    {
                        cnt++;
                    }
                }
            }

            ans = max(ans, cnt + 1);
        }
    }

    cout << ans << endl;
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