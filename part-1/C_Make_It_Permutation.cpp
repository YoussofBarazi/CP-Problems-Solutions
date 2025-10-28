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
    ll n , c , d , mx = 0;
    cin >> n >> c >> d;

    map <int , int> m;
    for (size_t i = 0; i < n; i++)
    {
        ll x ;
        cin >> x;

        m[x] ++;
        mx = max(mx , x);
    }
    
    vl p;
    ll ans = 0 , num = 1 , last = 0 , size = m.size();
    if (m[1] == 0)
        ans += d , m[1] ++ , size ++;

    for (auto x : m)
        ans += (x.S - 1) * c;

    for (auto x : m)
    {
        p.pb(ans + (size - last) * c);
        if (num != x.F)
        {
            ll y = 1e9;
            if (last)
                y = (x.F - last - 1) * d;

            size += x.F - last - 1;
            ans += y;   
        }

        last = x.F;
        num = x.F + 1;
    }

    sort(all(p));
    ans = min(ans , p.front());

    cout << ans << endl;
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