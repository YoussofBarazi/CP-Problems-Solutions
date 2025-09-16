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
    ll n, w;
    cin >> n >> w;

    vector<pair<ll, int>> a(n);
    ll sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F;
        a[i].S = i + 1;
        sum += a[i].F;
    }
    Sort(a);

    if (a[0].F > w || sum < (w + 1) / 2)
    {
        cout << "-1" << endl;
        return;
    }

    vi ans;
    int j = n - 1;
    sum = 0;
    while (j >= 0 && sum < (w + 1) / 2)
    {
        if (sum + a[j].F <= w)
        {
            ans.pb(a[j].S);
            sum += a[j].F;
        }

        j--;
    }

    if (sum < (w + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
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