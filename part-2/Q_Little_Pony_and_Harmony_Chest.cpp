#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 109;

vector<int> primes;
bool isprime[N];

void sieve(int n)
{
    for (size_t i = 0; i <= n; i++)
    {
        isprime[i] = true;
    }

    primes.push_back(1);

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

int n , a[N] , DP[N];

int dp(int i)
{
    if (i == n)
        return 0;
    
    int &ret = DP[i];

    if (ret != -1)
        return ret;

    ret = 1e6;

    for (int j = 0 ; j < primes.size() ; j++)
        ret = min(ret , dp(i + 1) + abs(a[i] - primes[j]));
    
    return ret;
}

void solve()
{
    sieve(100);

    cin >> n;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    memset(DP , -1 , sizeof DP);

    dp(0);

    for (int i = 0 ; i < n ; i ++)
        cout << DP[i] << " " ;
    cout << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}