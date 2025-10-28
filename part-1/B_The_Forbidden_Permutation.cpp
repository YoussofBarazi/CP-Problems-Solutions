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
    int n, m, d;
    cin >> n >> m >> d;

    vi a(m), p(n);
    map<int, int> pos;
    for (size_t i = 0; i < n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i + 1;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    int ans = 2e9;
    for (size_t i = 0; i < m - 1; i++)
    {
        if (pos[a[i]] > pos[a[i + 1]] || pos[a[i + 1]] > pos[a[i]] + d)
        {
            ans = 0;
            break;
        }

        if (pos[a[i]] < pos[a[i + 1]] && pos[a[i + 1]] <= pos[a[i]] + d)
        {
            if (n - pos[a[i + 1]] + pos[a[i]] - 1 >= pos[a[i]] + d + 1 - pos[a[i + 1]])
            {
                ans = min(pos[a[i]] + d + 1 - pos[a[i + 1]] , ans);
            }
            ans = min(pos[a[i + 1]] - pos[a[i]] , ans);
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