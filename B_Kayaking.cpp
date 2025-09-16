#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

    vector<int> a(2 * n);

    for (auto &x : a)
    {
        cin >> x;
    }

    sort(all(a));

    int ans = 1e6;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            vector<int> v;
            for (int k = 0; k < 2 * n; k++)
            {
                if (k == i || k == j)
                    continue;

                v.pb(a[k]);
            }

            int total = 0;
            for (int k = 1; k < v.size(); k += 2)
            {
                total += v[k] - v[k - 1];
            }
            ans = min(ans, total);
        }
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}