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
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> farm(1011, vector<ll>(1011, 0));
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        farm[x1][y1]++;
        farm[x1][y2]--;
        farm[x2][y1]--;
        farm[x2][y2]++;
    }

    int ans = 0;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (i > 0)
                farm[i][j] += farm[i - 1][j];
            if (j > 0)
                farm[i][j] += farm[i][j - 1];
            if (i > 0 && j > 0)
                farm[i][j] -= farm[i - 1][j - 1];

            ans += (farm[i][j] == k);
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