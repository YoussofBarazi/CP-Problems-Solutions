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

void solve()
{
    int n;
    scanf("%d", &n);

    int x;
    map<int, ll> freq;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        freq[x]++;
    }

    int q;
    scanf("%d", &q);

    while (q--)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);

        ll d = x * x - 4 * y;
        ll Sqrt = sqrt(d);

        if (d < 0 || Sqrt != sqrt(d))
        {
            printf("0 ");
            continue;
        }

        ll ans = 0;
        ll a = x + Sqrt;

        if (a % 2 == 0)
        {
            a /= 2;

            if (x == 2 * a)
                ans += freq[a] * (freq[a] - 1) / 2;
            else
                ans += freq[a] * freq[x - a];
        }

        ll b = x - Sqrt;

        if (b % 2 == 0 && x - a != b / 2)
        {
            b /= 2;

            if (x == 2 * b)
                ans += freq[b] * (freq[b] - 1) / 2;
            else
                ans += freq[b] * freq[x - b];
        }

        printf("%lld ", ans);
    }
    printf("\n");
}

int main()
{
    // IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}