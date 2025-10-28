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

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    bool ok = true;

    for (int i = 1; i < n; i++)
        ok &= a[i] > a[i - 1];

    int ans = 0;
    
    while (!ok)
    {
        int i = n - 1, mx = a[i];
        while (i > 0 && a[i] > a[0] && max(mx, a[i]) == mx)
            mx = a[i], i--;

        for (int j = 1; j <= i; j++)
            swap(a[j], a[j - 1]);

        ok = true;
        for (int i = 1; i < n; i++)
            ok &= a[i] > a[i - 1];

        ans++;
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