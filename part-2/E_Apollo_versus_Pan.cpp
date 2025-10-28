#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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
    int n;
    cin >> n;

    vector<ll> X(n);
    vector <int> freq(60 , 0);

    for (auto &x : X)
    {
        cin >> x;

        for (ll i = 0; i < 60; i++)
        {
            freq[i] += bool(x & (1ll << i));
        }
    
    
    }

    ll ans = 0, mod = 1e9 + 7;

    for (auto x : X)
    {
        ll a = 0, b = 0;
        
        for (ll i = 0; i < 60; i++)
        {
            ll t = (1ll << i) % mod;
         
            if (x & (1ll << i))
            {
                a += t * freq[i] % mod;
                a %= mod;
                
                b += t * n % mod;
                b %= mod;
            }
            else 
            {
                b += t * freq[i] % mod;
                b %= mod;
            }
        }

        ans += a * b % mod;
    }

    cout << ans % mod << endl;
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