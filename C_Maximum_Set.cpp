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
ll l, r;

bool check (ll m , int s , int type)
{
    for (size_t i = 1; i < s; i++)
    {
        m *= 2;
    }

    if (type == 2)
    {
        m /= 2;
        m *= 3;
    }

    return m <= r;
}

ll mul(ll a, ll b, ll m)
{
    return ((a % m) * (b % m)) % m;
}

void solve()
{
    cin >> l >> r;

    int size = 1;
    int tmp = l;
    while (tmp * 2 <= r)
    {
        size ++;
        tmp *= 2;
    }

    ll ans = 0;
    ll L = l , R = r;
    
    while (L < R)
    {
        int m = (L + R + 1) / 2;
        
        if (check(m , size , 1))
        {
            L = m;
        }
        else 
        {
            R = m - 1;
        }
    }

    ll L2 = l , R2 = r;
    while (L2 < R2)
    {
        int m = (L2 + R2 + 1) / 2;
        
        if (check(m , size , 2))
        {
            L2 = m;
        }
        else 
        {
            R2 = m - 1;
        }
    }

    if (check(L2 , size , 2)) ans = mul(L2 - l + 1 , size - 1 , 998244353);
    ans = (ans + L - l + 1) % 998244353;

    cout << size << " " << ans << endl;
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