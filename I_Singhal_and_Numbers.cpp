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

const int N = 1e7 + 9;

set <int> primefactor;
ll x , a , b , c;
ll mxprime = 0 , mxcomposite = 0;
void  primeFactors(int n)
{
    if (n % 2 == 0)
        mxprime = 2 , mxcomposite = max(x / 2 , mxcomposite);
    while (n % 2 == 0)
    {
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        if (n % i == 0)
            mxprime = i , mxcomposite = max(x / i , mxcomposite);
        while (n % i == 0)
        {
            n = n / i;
        }
    }

    if (n > 2 && x != n)
        mxprime = n , mxcomposite = max(x / n , mxcomposite);
}

void solve()
{
    cin >> x >> a >> b >> c;

    ll ans = c + x;
    
    primeFactors(x);
    
    if (mxprime > 0)ans = min(ans , a + x / mxprime);
    
    if (mxprime != mxcomposite)
    {
        ans = min (ans ,b + x / mxcomposite);
    }

    cout << ans << endl;
    mxprime = mxcomposite = 0;
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