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

void solve()
{
    int n;
    cin >> n;

    vi a(n), ans;
    vector<pair<int, int>> b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    sort(all(b));
    int x = b[n - 1].S;
    if (x == 0 && n > 1)
        x = b[n - 2].S;

    for (size_t i = x; i < n; i++)
    {
        ans.pb(a[i]);
    }

    set<vi> s;
    vi tmp = ans;

    if (x == n - 1)
    {
        vi temp;
        temp.pb(a[x]);
        for (size_t i = 0; i < x; i++)
        {
            temp.pb(a[i]);
        }

        s.insert(temp);
    }

    for (int i = x - 1; i >= 0; i--)
    {
        tmp.pb(a[i]);
        vi full = tmp;
        for (int j = 0; j < i; j++)
        {
            full.pb(a[j]);
        }
        s.insert(full);
    }

    ans = *(--s.end());

    for (size_t i = 0; i < n; i++)
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