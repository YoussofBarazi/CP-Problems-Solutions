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

vector<ll> sum[N];
vector<ll> sub(N, 0);

bool ok(ll m, ll add, ll sub, ll x, vector<ll> &s)
{
    ll sum = s[m] + (m + 1) * (add - sub);
    return sum <= x;
}

void solve()
{
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        sum[x].pb(a[i]);
    }

    for (int i = 0; i < N; i++)
        for (int j = 1; j < sum[i].size(); j++)
            sum[i][j] += sum[i][j - 1];

    int q;
    cin >> q;

    ll add = 0;
    while (q--)
    {
        ll t, col, x;
        scanf("%lld %lld %lld", &t, &col, &x);

        if (t == 1)
            sub[col] += x, add += x;
        else
        {
            int l = 0, r = sum[col].size() - 1;

            while (l < r)
            {
                int m = (l + r + 1) / 2;

                if (ok(m, add, sub[col], x, sum[col]))
                    l = m;
                else
                    r = m - 1;
            }

            if (ok(l, add, sub[col], x, sum[col]))
                printf("%d\n", l + 1);
            else
                printf("0\n");
        }
    }
}

int main()
{
    // IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}