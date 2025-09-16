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

int f(vl &a, ll x)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ll root = sqrt(a[i] + x);
        if (root * root == a[i] + x)
            cnt++;
    }

    return cnt;
}

void solve()
{
    int n;
    cin >> n;

    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll num = a[j] - a[i];

            for (ll d = 1; d * d <= num; d++)
            {
                if (num % d == 0)
                {
                    ll x = num / d - d;

                    if (x % 2 == 0)
                    {
                        x /= 2;
                        ll p_ans = x * x - a[i];

                        if (p_ans >= 0)
                            ans = max(ans, f(a, p_ans));
                    }
                }
            }
        }
    }
    cout << ans << endl;
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