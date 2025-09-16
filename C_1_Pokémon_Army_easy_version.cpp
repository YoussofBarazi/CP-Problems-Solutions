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
    int n , q;
    cin >> n >> q;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vl d1(n + 1 , 0) , d2(n + 1 , 0);
    d1[0] = INT_MIN;
    d2[0] = 0;
    
    for (size_t i = 0; i < n; i++)
    {
        d1[i + 1] = max(d2[i] + a[i] , d1[i]);
        d2[i + 1] = max(d2[i] , d1[i] - a[i]);
    }

    cout << max(d1[n] , d2[n]) << endl;
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