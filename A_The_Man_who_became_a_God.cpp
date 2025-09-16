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
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    priority_queue<int> q;

    for (int i = 1; i < n; i++)
        q.push(abs(a[i] - a[i - 1]));

    while (--k)
        q.pop();

    int ans = 0;

    while (q.size())
        ans += q.top(), q.pop();

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