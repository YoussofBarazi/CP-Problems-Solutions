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
vi a;

int left(int x)
{
    return lower_bound(a.begin() + 1, a.end(), x) - a.begin();
}

int right(int x)
{
    return upper_bound(a.begin() + 1, a.end(), x) - a.begin();
}

void solve()
{
    int n;
    cin >> n;

    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    int k;
    cin >> k;

    while (k--)
    {
        int l, r;
        cin >> l >> r;

        cout << right(r) - left(l) << " ";
    }
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