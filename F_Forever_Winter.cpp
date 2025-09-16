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
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> a(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        a[u].pb(v);
        a[v].pb(u);
    }

    int center = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 1;
        for (int j = 1; j < a[i].size(); j++)
        {
            if (a[a[i][j]].size() == a[a[i][j - 1]].size() && a[a[i][j]].size() > 1)
                cnt++;
        }

        if (cnt == a[i].size() && a[i].size() > 1)
        {
            center = i;
            break;
        }
    }

    printf("%d ", a[center].size());

    for (auto x : a[center])
    {
        for (int j = 0; j < a[x].size(); j++)
        {
            if (a[x][j] != center)
            {
                printf("%d\n", a[x].size() - 1);
                return;
            }
        }
    }
}

int main()
{
    // IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}