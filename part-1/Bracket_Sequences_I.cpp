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

const int N = 200009 , mod = 1e9 + 7;

int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

void solve()
{
    int n;
    cin >> n;

    if (n & 1) {
        cout << 0 << endl;
        return ;
    }

    vector <ll> fact(n + 1 , 1);

    for (int i = 2 ; i <= n ; i ++)
        fact[i] = fact[i - 1] * i % mod;

    ll ans = fact[n] * inv(fact[n / 2] * fact[n / 2] % mod) % mod;
    ans *= inv(n / 2 + 1);

    cout << ans % mod;   
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