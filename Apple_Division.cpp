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

int n, a[21];
ll total = 0, res = LONG_LONG_MAX;

void complete_search(int i, ll sum)
{
    if (i == n)
    {
        res = min(res, abs(total - 2 * sum));
        return;
    }

    complete_search(i + 1, sum);
    complete_search(i + 1, sum + a[i]);

    return;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    complete_search(0, 0);

    cout << res << endl;
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