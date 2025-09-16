#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

bool cmp(pi a, pi b)
{
    return a.y < b.y;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> cow(n);
    for (auto &c : cow)
        cin >> c.x >> c.y;

    sort(all(cow));
    int ind = 1;
    for (int i = 0; i < n; i++)
    {
        cow[i].x = ind;
        ind += 2;
    }

    sort(all(cow), cmp);
    // for (int i = 0; i < n; i++)
    //     cout << cow[i].y << " ";
    // cout << endl;
    ind = 1;

    for (int i = 0; i < n; i++)
    {
        cow[i].y = ind;
        ind += 2;
    }

    vector<vector<int>> grid(2 * n + 1, vector<int>(2 * n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        grid[cow[i].x][cow[i].y]++;
        // cout << cow[i].x << " " << cow[i].y << endl;
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            // cout << grid[i][j] << " ";
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
        cout << endl;
    }

    int mn = n;
    for (int i = 2; i <= 2 * n; i += 2)
    {
        for (int j = 2; j <= 2 * n; j += 2)
        {
            int ans1 = grid[i][j];
            int ans2 = grid[i][2 * n] - grid[i][j] - grid[0][2 * n] + grid[0][j];
            int ans3 = grid[2 * n][j] - grid[2 * n][0] - grid[i][j] + grid[i][0];
            int ans4 = grid[2 * n][2 * n] - grid[2 * n][j] - grid[i][2 * n] + grid[i][j];

            mn = min(mn, max({ans1, ans2, ans3, ans4}));
        }
    }

    cout << mn << endl;
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