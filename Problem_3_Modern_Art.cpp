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

struct rec
{
    int s1, s2, s3, s4;
};

void solve()
{
    int n;
    cin >> n;

    vector<rec> v(10, {10, -1, 10, -1});
    vector<string> s(n);

    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<bool> first(10, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[s[i][j] - '0'].s1 = min(v[s[i][j] - '0'].s1, i);
            v[s[i][j] - '0'].s2 = max(v[s[i][j] - '0'].s2, i);
            v[s[i][j] - '0'].s3 = min(v[s[i][j] - '0'].s3, j);
            v[s[i][j] - '0'].s4 = max(v[s[i][j] - '0'].s4, j);
            first[s[i][j] - '0'] = true;
        }
    }

    for (int c = 1; c < 10; c++)
    {
        for (int i = v[c].s1; i <= v[c].s2; i++)
        {
            for (int j = v[c].s3; j <= v[c].s4; j++)
            {
                if (s[i][j] - '0' != c)
                    first[s[i][j] - '0'] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 10; i++)
        ans += first[i];

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