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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

bool composite[N + 1];
vector<int> primes;

void linear_sieve(int N)
{
    composite[0] = composite[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (!composite[i])
        {
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= N; ++j)
        {
            composite[i * primes[j]] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    linear_sieve(n);
    int cnt = 0;
    for (size_t x = 0; x < primes.size(); x++)
    {
        for (size_t i = 1; i < primes.size(); i++)
        {
            if (primes[i] + primes[i - 1] + 1 == primes[x])
                cnt ++;
        }

        if (cnt == k)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}