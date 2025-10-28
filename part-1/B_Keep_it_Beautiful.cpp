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
    int q;
    cin >> q;

    vector<int> v, w;

    vector<bool> ans(q, false);
    int i = 0;
    for (; i < q; i++)
    {
        int x;
        cin >> x;

        if (v.size() == 0)
            v.pb(x), ans[i] = true;
        else if (x >= v.back())
            v.pb(x), ans[i] = true;
        else if (x <= v.front())
        {
            w.pb(x), ans[i] = true;
            break;
        }
    }
    i++;
    for (; i < q; i++)
    {
        int x;
        cin >> x;

        if (x >= w.back() && x <= v.front())
        {
            w.pb(x), ans[i] = true;
        }
    }

    for (size_t i = 0; i < q; i++)
    {
        cout << ans[i];
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