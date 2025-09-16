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

    vector<vector<int>> a(n, vector(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            s.insert(a[i][j]);
        }

        if (s.size() == n)
            cnt++;
    }

    for (int j = 0; j < n; j++)
    {
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i][j]);
        }

        if (s.size() == n)
            cnt++;
    }

    if (cnt == n * 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}