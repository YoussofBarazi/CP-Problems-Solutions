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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 1e5;
    if (k != 4)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % k == 0)
                ans = 0;
            ans = min(ans, k - a[i] % k);
        }
    }
    else
    {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % k == 0)
            {
                ans = 0;
            }

            ans = min(ans, k - a[i] % k);
            cnt0 += a[i] % 2 == 0;
            cnt1 += a[i] % 2;
        }

        int ans1 = 1e5;
        if (cnt0 >= 2)
            ans1 = 0;
        else if (cnt0 == 1 && cnt1 >= 1)
            ans1 = 1;
        else if (cnt1 >= 2)
            ans1 = 2;
        else if (cnt0 == 1)
            ans1 = 2;
        else
            ans1 = 3;

        ans = min(ans1, ans);
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