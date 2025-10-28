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
    int k, n;
    cin >> k >> n;

    vector<vector<int>> a(k, vector(n, 0));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;

            a[i][x - 1] = j;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cnt1 = 0, cnt2 = 0;
            for (int w = 0; w < k; w++)
            {
                cnt1 += a[w][i] < a[w][j];
                cnt2 += a[w][i] > a[w][j];
            }

            ans += (cnt1 == k || cnt2 == k);
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