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
    int n , x;
    cin >> n >> x;

    vector <pair<int , int>> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F;
        a[i].S = i + 1;
    }
    sort(all(a));

    int l = 0 , r = n - 1;
    while (l < r)
    {
        if (a[l].F + a[r].F == x)
        {
            cout << a[l].S << " " << a[r].S << endl;
            return;
        }
        else if (a[l].F + a[r].F > x)
            r --;
        else 
            l ++;
    }

    cout << "IMPOSSIBLE" << endl;
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