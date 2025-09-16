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

ll mod = 998244353;
vector<int> cnt(21, 0);

ll Fl(vector<int> &d , int len)
{
    ll pow = 1 , ans = 0;
    for (int i = 0; i < max((int)d.size(), len); i++)
    {
        if (i < len)
        {
            pow = pow * 10 % mod;
        }
        if (i < d.size())
        {
            ans += d[i] * pow;
            pow = pow * 10 % mod;
        }
    }

    return ans % mod;
}

ll Fr(vector<int> &d, int len)
{
    ll pow = 1 , ans = 0;
    for (int i = 0; i < max((int)d.size(), len); i++)
    {
        if (i < d.size())
        {
            ans += d[i] * pow;
            pow = pow * 10 % mod;
        }
        if (i < len)
        {
            pow = pow * 10 % mod;
        }
    }

    return ans % mod;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &x : a)
    {
        cin >> x;
    }

    sort(allrev(a));

    for (auto x : a)
    {
        int c = 0;

        while (x > 0)
        {
            x /= 10;
            c++;
        }

        cnt[c]++;
    }

    int len = 0;

    for (int i = 0; i < 21; i++)
        len = max((cnt[i] > 0) * i, len);

    ll ans = 0;

    for (int x : a)
    {
        vector<int> digits;

        while (x > 0)
        {
            digits.pb(x % 10);
            x /= 10;
        }

        for (int l = 1 ; l <= len ; l ++)
        {
            ans += cnt[l] * (Fl(digits , l) + Fr(digits , l));
            ans %= mod;
        }
    }

    cout << ans << endl;
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