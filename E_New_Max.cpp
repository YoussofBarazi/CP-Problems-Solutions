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
    int n, m, k;
    cin >> n >> m >> k;

    int x;
    int mx = 0, tmp = k;
    while (n--)
    {
        cin >> x;

        if (x > m)
            k--;
        mx = max(mx, x);
    }

    if (k < 0 || (tmp == 0 && mx != m))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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