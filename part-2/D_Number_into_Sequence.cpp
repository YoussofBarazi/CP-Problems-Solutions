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

vl primefactor;
map <ll , ll> m;
void get(ll n)
{
    while (n % 2 == 0)
    {
        primefactor.pb(2);
        n /= 2;
        m[2] ++;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            primefactor.pb(i);
            m[i] ++;
            n /= i;
        }
    }
    
    if (n > 2)
    {
        m[n] ++;
        primefactor.pb(n);
    }
}

void solve()
{
    ll n;
    cin >> n;

    primefactor.clear();
    m.clear();
    
    get(n);
    ll mx = 0 , x = 1;
    
    for (auto w : m)
    {
        if (mx < w.S)
        {
            x = w.F;
            mx = w.S;
        }
    }

    ll y = 1;
    for (size_t i = 0; i < primefactor.size(); i++)
    {
        if (primefactor[i] != x)
            y *= primefactor[i];
    }

    cout << mx << endl;
    for (size_t i = 0; i < mx - 1; i++)
    {
        cout << x << " " ;
    }
    cout << x * y << endl;
    
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