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

map<int, int> prime;
void Factorize(int n)
{
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            prime[i]++;
            n /= i;
        }
    }

    if (n > 2)
        prime[n]++;
}

void solve()
{
    int n;
    cin >> n;

    int make_power_of_two = 0;
    int mn = 0;
    int ans = 1;

    Factorize(n);

    for (auto x : prime)
    {
        mn = max((int)ceil(log2(x.S)), mn);
    }
    for (auto x : prime)
    {
        make_power_of_two += ((1 << mn) != x.S);
        ans *= x.F;
    }

    mn += make_power_of_two > 0;

    cout << ans << " " << mn << endl;
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