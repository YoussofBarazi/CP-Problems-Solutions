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

    if (n < 3)
    {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        return;
    }

    vector<int> ans(n, 0);
    ans[0] = 2, ans[n - 1] = 3, ans[n / 2] = 1;

    int cnt = 4;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            ans[i] = cnt++;
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
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