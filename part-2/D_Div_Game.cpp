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

int primeFactors(ll n)
{
    int cnt = 0, ans = 0;
    while (n % 2 == 0)
    {
        n = n / 2;
        cnt++;
    }
    int sum = 0;
    for (size_t i = 1; i <= cnt; i++)
    {
        sum += i;
        if (sum <= cnt)
            ans++;
        else
            break;
    }

    for (ll i = 3; i * i <= n; i = i + 2)
    {
        cnt = 0;
        while (n % i == 0)
        {
            n = n / i;
            cnt++;
        }
        int sum = 0;
        for (size_t i = 1; i <= cnt; i++)
        {
            sum += i;
            if (sum <= cnt)
                ans++;
            else
                break;
        }
    }

    if (n > 2)
        ans++;

    return ans;
}

void solve()
{
    ll n;
    cin >> n;

    cout << primeFactors(n) << endl;
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