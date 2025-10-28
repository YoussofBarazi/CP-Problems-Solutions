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
vl a;
ll n, mem[N];

ll dp (int i)
{
    if (i == n) return 0;
    if (mem[i] != LONG_LONG_MIN) return mem[i];

    ll ans2 = dp (i + 2) - a[i] - a[i + 1]; 
    ll ans1 = dp (i + 1) + a[i];

    mem[i] = max(ans1 , ans2);
    return mem[i];
}

void solve()
{
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        mem[i] = LONG_LONG_MIN;
    }

    a.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a.pb(LONG_MAX);

    cout << dp(0) << endl;
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