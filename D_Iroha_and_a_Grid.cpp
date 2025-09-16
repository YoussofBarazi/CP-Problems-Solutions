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
const int MOD = 1e9 + 7;

int inv(int i)
{
    return i <= 1 ? i : MOD - (long long)(MOD / i) * inv(MOD % i) % MOD;
}

vector <ll> fact(N);

ll C(int n , int r) {
    return fact[n] * inv(fact[r] * fact[n - r] % MOD) % MOD;
}

void solve()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    int x = h - a;
    int y = b + 1;

    fact[0] = 1;
    for (int i = 1 ; i <= 2 * max(h , w) ; i ++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }

    ll ans = 0;

    for (y ; y <= w ; y ++) {
        ans += C(x + y - 2 , x - 1) * C(h - x + w - y - 1 , h - x - 1) % MOD;
    }

    cout << ans % MOD << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}