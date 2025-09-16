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

const int N = 10000009;

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

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;

    int cnt = 1;
    if (is_prime(n))
    {
        cout << "1\n"
             << n << endl;
        return;
    }

    int t = n;
    n -= 3;

    for (size_t i = 0; i < prime.size(); i++)
    {
        if (prime[i] > t)
            break;
        if (t - prime[i] <= N && !composite[t - prime[i]])
        {
            cout << "2\n"
                 << prime[i] << " " << t - prime[i] << endl;
            return;
        }
    }

    for (size_t i = 0; i < prime.size(); i++)
    {
        if ((n - prime[i] <= N && !composite[n - prime[i]]) || is_prime(n - prime[i]))
        {
            cout << "3\n3 " << prime[i] << " " << n - prime[i] << endl;
            return;
        }
    }
}

int main()
{
    IOS;
    linear_sieve(1e7);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}