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

vector<int> primes;
bool isprime[N];

void sieve(int n)
{
    for (size_t i = 0; i <= n; i++)
    {
        isprime[i] = true;
    }

    for (size_t i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            for (size_t j = i * 2; j <= n; j += i)
            {
                isprime[j] = false;
            }
            primes.pb(i);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    sieve(sqrt(1e7));

    vector<int> d1(n, -1), d2(n, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> factors = {1};
        int tmp = a[i], x = 1;

        for (auto p : primes)
        {
            if (p > tmp)
                break;

            if (tmp % p == 0)
            {
                factors.pb(p);
                x *= p;
            }

            while (tmp % p == 0)
                tmp /= p;
        }

        if (tmp > 1)
            factors.pb(tmp), x *= tmp;

        for (int j = 1; j < factors.size() - 1; j++)
        {
            factors[j] *= factors[j - 1];
            if (gcd(factors[j] + x / factors[j], a[i]) == 1)
                d1[i] = factors[j], d2[i] = x / factors[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (d1[i] == -1 || d2[i] == -1)
            cout << -1 << " ";
        else
            cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (d1[i] == -1 || d2[i] == -1)
            cout << -1 << " ";
        else
            cout << d2[i] << " ";
    }
    cout << endl;
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