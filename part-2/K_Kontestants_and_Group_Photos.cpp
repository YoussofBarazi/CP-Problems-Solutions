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

const int N = 5009;

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

vector <ll> fact(N);

int C(int n, int r) {
    return fact[n] * inv(fact[r] * fact[n - r] % mod) % mod;
}

int dp[N][N];

void solve()
{
    int n;
    cin >> n;

    vector <int> a(n + 1);
    for (int i = 1 ; i <= n ; i ++) {
        cin >> a[i];
        dp[i][a[i]] = 1;
    }

    fact[0] = 1;
    for (int i = 1 ; i <= n ; i ++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
    }
    ll ans = 0;
    for (int i = 1 ; i <= n ; i ++) {
        ans += C(n, i);
        ans %= mod;
    }
    cout << ans << endl;
    sort(all(a));
    dp[0][0] = 1;

    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 0 ; j <= 5e3 ; j ++) {

        }
    }

    for (int i = 1 ; i <= n ; i ++) {
        ans -= dp[n][a[i]];
        ans += mod;
        ans %= mod;
    }

    cout << ans << endl;
}

int main()
{
    // freopen("polygon.in", "r", stdin);
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}