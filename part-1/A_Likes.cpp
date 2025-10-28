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

    vi a(n), b;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            b.pb(a[i]);
    }
    sort(allrev(a));

    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        cnt += a[i] > 0;
        cnt -= a[i] < 0;

        cout << cnt << " ";
    }
    cout << endl;

    cnt = 0;
    for (size_t i = 0; i < b.size(); i++)
    {
        cnt++;
        cout << cnt << " ";
        if (n - b.size() >= i + 1)
            cout << --cnt << " ";
    }
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