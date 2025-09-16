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

map<int, int> freq;

void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        freq[2]++;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            freq[i]++;
            n = n / i;
        }
    }

    if (n > 2)
        freq[n]++;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        primeFactors(a[i]);
    }

    int ans = 0, cnt = 0;
    for (auto x : freq)
    {
        ans += x.S / 2;
        cnt += x.S % 2;
    }
    ans += cnt / 3;

    cout << ans << endl;
    freq.clear();
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}