#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

ll fact[N];

ll C(int n , int r)
{
    return fact[n] * inv(fact[r] * fact[n - r] % mod) % mod;
}

void solve()
{
    int n , k;
    cin >> n >> k;

    int cnt0 = 0 , cnt1 = 0;

    for (int i = 1 ; i <= n ; i ++)
    {
        int x;
        cin >> x;

        cnt0 += !x;
        cnt1 += x; 
    }

    ll ans = 0;

    for (int c0 = 0 ; c0 <= k ; c0 ++)
    {
        int c1 = k - c0;
        if (c0 > cnt0 || c1 > cnt1)
            continue;
        
        ans += C(cnt0 , c0) * C(cnt1 , c1) * (c0 < c1) % mod;
        ans %= mod;
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    fact[0] = fact[1] = 1;
    for (int i = 2 ; i <= 2e5 ; i ++)
        fact[i] = fact[i - 1] * i % mod;
    
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}