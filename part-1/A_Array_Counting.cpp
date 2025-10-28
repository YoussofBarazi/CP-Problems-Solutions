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

const int N = 1000009;
const ll mod = 1e9 + 7;

int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

vector <ll> fact(N);

ll C(int n , int r) {
    if (r > n) return 0;
    return fact[n] * inv(fact[n - r] * fact[r] % mod) % mod;
}

void solve()
{
    ll n, s, g;
    cin >> n >> s >> g;

    if (s % g || s < n * g) {
        cout << 0 << endl; 
        return ; 
    } else if (n == 1) {
        if (s == g) cout << 1 << endl;
        else cout << 0 << endl;
        return ;
    } else if (s == n * g) {
        cout << 1 << endl;
        return ;
    }

    s /= g;

    if (s % n) {
        cout << C(n, s % n) << endl;
    } else {
        ll ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            ans += C(n, i) * C(n - i, i) % mod;
        }

        cout << ans % mod << endl;
    }
}

int main()
{
    IOS;

    fact[0] = 1;
    for (int i = 1 ; i < N ; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}