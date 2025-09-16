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

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (a[n - 1] == 1)
    {
        cout << "NO" << endl;
        return;
    }

    vi b, ans;

    int i = n - 1;

    while (i >= 0)
    {
        while (i >= 0 && a[i] == 0)
        {
            ans.pb(0);
            i--;
        }

        int cnt = 0;
        while (i >= 0 && a[i] == 1)
        {
            ans.pb(0);
            cnt++;
            i--;
        }
        ans.pop_back();
        ans.pb(cnt);
    }

    cout << "YES" << endl;
    for (auto x : ans)
        cout << x << " ";
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