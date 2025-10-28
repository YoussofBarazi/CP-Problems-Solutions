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
    double n , m , k;
    cin >> n >> m >> k;

    int l = 0 , r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (m * 100 / n >= 70)
            r = m;
        else 
            l = m + 1;
    }

    int needed = l;

    if (needed - k > n - m)
        cout << -1 << endl;
    else 
        cout << max(int(needed - k) , 0) << endl;

    cout << int((n - m + k) / n * 100) << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}