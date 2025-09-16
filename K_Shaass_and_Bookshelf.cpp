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

void solve()
{
    int n;
    cin >> n;

    vi a, b;
    int sum = 0;
    int ans = 0, s = 0, tmp = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x == 1)
            a.pb(y), ans++;
        else
            b.pb(y), ans += 2;

        sum += y;
    }

    Rsort(a), Rsort(b);

    for (size_t j = 0; j <= b.size(); j++)
    {
        for (size_t k = 0; k <= a.size(); k++)
        {
            s = 0, tmp = sum;
            for (size_t i = 0; i < a.size() - k; i++)
            {
                tmp -= a[i];
                s++;
            }
            for (size_t i = 0; i < b.size() - j; i++)
            {
                tmp -= b[i];
                s += 2;
            }

            if (s >= tmp)
                ans = min(s, ans);
        }
    }

    cout << ans << endl;
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