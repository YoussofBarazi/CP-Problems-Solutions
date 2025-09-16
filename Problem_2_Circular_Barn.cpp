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

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1, res = 0;
        for (int j = i + 1; j < n; j++)
        {
            res += cnt * a[j];
            cnt++;
        }
        for (int j = 0; j < i; j++)
        {
            res += cnt * a[j];
            cnt++;
        }

        ans = min(ans, res);
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