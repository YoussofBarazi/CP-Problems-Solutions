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

    vector<pi> ans;
    int x, cnt1 = 0, cnt2 = 0;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> x;

        if (x == 0)
        {
            if (cnt2 > 0)
            {
                ans.pb({i - cnt2, i - 1});
            }

            if (cnt1 > 0)
            {
                ans.pb({i - cnt1, i - 1});
            }
    
            ans.pb({i, i});
            cnt1 = cnt2 = 0;
        }
        else if (x > 0)
        {
            if (cnt2 > 0)
            {
                ans.pb({i - cnt2, i - 1});
                if (cnt2 % 2)
                    ans.pb({i, i}), cnt1--;
            }

            cnt1++;
            cnt2 = 0;
        }
        else
        {
            if (cnt1 > 0)
            {
                ans.pb({i - cnt1, i - 1});
                if (cnt1 % 2)
                    ans.pb({i, i}), cnt2--;
            }
            cnt2++;
            cnt1 = 0;
        }
    }

    if (cnt2 > 0)
    {
        ans.pb({n - cnt2 + 1, n});
    }

    if (cnt1 > 0)
    {
        ans.pb({n - cnt1 + 1, n});
    }

    if ((cnt1 + cnt2) % 2)
    {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.F << " " << x.S << endl;
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