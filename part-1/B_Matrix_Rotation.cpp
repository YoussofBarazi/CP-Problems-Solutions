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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if (a < b && a < c && b < d && c < d)
    {
        cout << "YES" << endl;
    }
    else if (c < a && c < d && a < b && d < b)
    {
        cout << "YES" << endl;
    }
    else if (d < c && d < b && c < a && b < a)
    {
        cout << "YES" << endl;
    }
    else if (b < a && b < d && d < c && a < c)
    {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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