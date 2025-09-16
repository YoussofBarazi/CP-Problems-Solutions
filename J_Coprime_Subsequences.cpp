#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 1009;

ll MOD(ll x, ll mod)
{
    return (x % mod + mod) % mod;
}

ll POW_M(ll x, ll y, ll mod)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return MOD(x, mod);

    ll ans = POW_M(x, y / 2, mod);

    if (y & 1)
        return MOD(MOD(ans * ans, mod) * x, mod);
    return MOD(ans * ans, mod);
}

int GPF[N];
vector<int> a, freq(N, 0);

void precalc()
{
    for (int i = 2 ; i < N ; i ++)
        if (!GPF[i])
            for (int j = i ; j < N ; j += i)
                GPF[j] = i;
}

void O_O(int i , int mul , int val , vector <int> &f , vector <int> &values)
{
    if (i == f.size())
    {
        freq[mul] += val;

        if (val == 1 && mul != 1) values.pb(mul);
        
        return;
    }

    O_O(i + 1 , mul * f[i] , val , f , values);
    O_O(i + 1 , mul , val , f , values);
}

void solve()
{
    int n , mod = 1e9 + 7;
    cin >> n;

    precalc();
    ll ans = 0;

    vector <int> div[N] , factor[N];
    int cnt = n;
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        a.pb(x);

        if (x == 1)
        {
            ans += POW_M(2 , --cnt , mod);
            continue;
        }

        while (x > 1)
        {
            int g = GPF[x];

            factor[i].pb(g);

            while (x % g == 0)
                x /= g;
        }
        
        O_O(0 , 1 , 1 , factor[i] , div[i]);
    }
    
    for (int i = 0 ; i < n ; i ++)
    {
        if (a[i] == 1)
            continue;

        int cnt = 0;

        for (auto d : div[i])
            cnt = max(cnt , freq[d]);

        if ((n - i) - cnt) // i = 1 , cnt = 1 
        {
            ans += POW_M(2 , n - i - 1 , mod);
            ans -= POW_M(2 , cnt - 1 , mod);
            ans += mod;

            ans %= mod;
        }

        O_O(0 , 1 , -1 , factor[i] , div[i]);
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}