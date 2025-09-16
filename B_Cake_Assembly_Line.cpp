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

ll n , w , h;
vl a , b;

int check (ll m)
{
    for (size_t i = 0; i < n; i++)
    {
        ll la , lb , ra , rb;
        
        la = (a[i] - m) - w;
        ra = (a[i] - m) + w;
        lb = b[i] - h;
        rb = b[i] + h;

        if (la > lb)
            return 1;
        if (ra < rb)
            return 2;
    }
    
    return 0;
}

void solve()
{
    cin >> n >> w >> h;

    a.resize(n) , b.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += 1e10;
    }

    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll l = 0, r = 1e15 , m;

    while (l <= r)
    {
        m = (l + r) / 2;
        int c = check(m);

        if (c == 0)
        {
            cout << "YES" << endl;
            return;
        }
        else if (c == 2) 
        {
            r = m - 1;
        }
        else 
        {
            l = m + 1;
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