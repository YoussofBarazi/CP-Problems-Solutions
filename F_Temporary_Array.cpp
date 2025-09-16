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
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> left(n + 2, 0), right(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        left[i] = left[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        right[i] = right[i + 1] + a[i];
    }

    reverse(all(right));

    while (q--)
    {
        ll s;
        cin >> s;

        int i1 = upper_bound(all(left), s) - left.begin();
        int i2 = upper_bound(all(right), s) - right.begin();

        cout << max(n - i1 - i2 + 2, 0) << endl;
    }
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