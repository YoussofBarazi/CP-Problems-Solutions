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

    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].pb(b);
    }

    for (auto &x : v)
        sort(allrev(x));

    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> on;

    for (int i = 1; i <= n; i++)
    {
        for (auto y : v[i])
        {
            if (on.size() == i)
                break;

            while (on.size() && on.top() <= on.size())
                on.pop();

            on.push(i);
            ans += y;
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