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

    int x, cnt1 = 0, cnt2 = 0, last_pos = 0, last_neg = 0;
    set<pi> ans;
    vi a(n + 2, 2);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            if (a[i + 1] == -1 && cnt2 % 2)
            {
                ans.insert({i, i + 1});
                cnt2 = 0;
                i++;
            }
            else if (a[i + 1] == 1 && cnt1 % 2)
            {
                ans.insert({i, i + 1});
                cnt1 = 0;
                i++;
            }
            else
            {
                ans.insert({i, i});
            }
        }
        else if (a[i] > 0)
        {
            if (cnt2 % 2)
                ans.insert({i, i}), cnt1--;

            cnt1++;
            last_pos = i;
            cnt2 = 0;
         
            if (a[i] != a[i + 1] && cnt1 > 0)
            {
                ans.insert({i - cnt1 + 1, i});
                cnt1 = cnt1 % 2;
            }
        }
        else
        {
            if (cnt1 > 0)
            {
                if (cnt1 % 2)
                    ans.insert({i, i}), cnt2--;
            }

            cnt2++;
            last_neg = i;
            cnt1 = 0;

            if (a[i] != a[i + 1] && cnt2 > 0)
            {
                ans.insert({i - cnt2 + 1, i});
                cnt2 = cnt2 % 2;
            }
        }
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