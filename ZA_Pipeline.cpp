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

ll arithmetic_progression(ll first, ll last, ll size)
{
    return ((first + last) * size) / 2;
}

ll check (ll n , ll k , ll m)
{
    return arithmetic_progression(m , k , k - m + 1);
}

void solve()
{
    ll n , k;
    cin >> n >> k;

    ll all = arithmetic_progression(2 , k , k - 1) - (k - 2);

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    else if (n <= k)
    {
        cout << 1 << endl;
        return;
    }
    else if (all < n)
    {
        cout << -1 << endl;
        return;
    }
    
    n -- , k --;
    ll l = 0 , r = k , m;

    while (l < r)
    {
        m = (l + r) / 2;

        if (check(n , k , m) == n)
        {
            cout << k - m + 1 << endl;
            return;
        }
        else if (check(n , k , m) < n)
        {
            r = m;
        }
        else 
        {
            l = m + 1;
        }
    }

    cout << k - l + 2 << endl;
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