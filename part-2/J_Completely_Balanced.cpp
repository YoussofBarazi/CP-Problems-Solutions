// wrong
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

void solve()
{
    ll n;
    scanf("%lld", &n);

    ll sum = 0;
    vector<long long> a(n + 1, LONG_LONG_MIN);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    sort(all(a));
    int mid = (n + 2) / 2;

    long long x1 = a[mid] * (n + 1) - sum;
    long long x2 = LONG_LONG_MAX;

    if (mid > 1)
        x2 = a[mid - 1] * (n + 1) - sum;

    printf("%lld\n", min(x1, x2));
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}