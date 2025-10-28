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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int c = a[0], cnt = 0, i = 0;
    for (; i < n; i++)
    {
        if (c == a[i])
            cnt++;

        if (cnt == k)
            break;
    }

    if (cnt >= k && a.back() == a.front())
    {
        cout << "YES" << endl;
        return;
    }

    c = a.back(), cnt = 0;
    for (int j = n - 1; i < j; j--)
    {
        if (c == a[j])
            cnt++;

        if (cnt % k == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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