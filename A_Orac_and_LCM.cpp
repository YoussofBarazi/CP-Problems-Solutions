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

bool composite[N + 1];
vector<int> prime;

void linear_sieve(int N)
{
    composite[0] = composite[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (!composite[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] <= N; ++j)
        {
            composite[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    linear_sieve(N);

    ll res = 1;

    for (int p : prime)
    {
        ll x = 1, mx = 1;
        for (int power = 1; power < 20; power++)
        {
            x *= p;

            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                cnt += a[i] % x != 0;
                if (cnt == 2)
                    break;
            }

            if (cnt <= 1)
                mx = x;
            else
                break;
        }

        // cout << p << " " << mx << endl;
        res *= mx;
    }

    cout << res << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}