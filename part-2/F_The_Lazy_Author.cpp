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
    int n, k;
    cin >> n >> k;

    vi a(n + 1);
    int one = 0;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> a[i];
        one += a[i];
    }

    if (one >= n - k / 2)
    {
        cout << 0 << endl;
        return;
    }

    vi update(n + 10, 0);

    one = 0;
    vector<int> ans;
    for (size_t i = 1; i <= n - k + 1; i++)
    {
        update[i] += update[i - 1];
        if ((a[i] + update[i]) % 2 == 0)
        {
            ans.pb(i);
            update[i + 1]++;
            update[i + k]--;
        }
        one++;

        if (one >= n - k / 2)
            break;
    }

    for (size_t i = n - k + 2; i <= n; i++)
    {
        update[i] += update[i - 1];
        one += (update[i] + a[i]) % 2;
    }

    if (one < n - k / 2)
        ans.pb(n - k + 1);

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
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}