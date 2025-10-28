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

    vi a(1010, 0);

    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[x]++;
    }

    int x = 1, cnt = 1, ans = 0;

    while (x <= 1000)
    {
        while (!a[x])
            x++;
        while (x < 1000 && a[x] == a[x + 1] && a[x])
        {
            cnt++, x++;
        }
        if (x - cnt == 0)
        {
            if (cnt == 1000)
                ans = max(cnt , ans);
            else
                ans = max(ans , cnt - 1);
        }
        else
        {
            if (x >= 1000)
                ans = max(cnt - 1 , ans);
            else 
                ans = max(cnt - 2 , ans);
        }
        cnt = 1;
        x++;
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