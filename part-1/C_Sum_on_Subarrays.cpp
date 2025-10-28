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

    int x = n;
    while (x * (x + 1) / 2 > k) x --;
    int r = k - x * (x + 1) / 2;

    for (size_t i = 0; i < x; i++)
    {
        if (i == r - 1) cout << 2 << " ";
        else cout << 1 << " ";
    }
    
    if (n - x > 0) cout << r - x - 1 << " ";

    for (size_t i = x + 1; i < n; i++)
    {
        cout << -1000 << " ";
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