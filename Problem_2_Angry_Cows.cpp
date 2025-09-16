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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1, dist = 1;
        int x = i;
        for (int j = i + 1; j < n;)
        {
            bool ok = false;
            while (j < n && abs(a[x] - a[j]) <= dist)
                cnt++, j++, ok = true;
            dist++;

            x = j - 1;

            if (!ok)
                break;
        }
        dist = 1, x = i;
        for (int j = i - 1; j >= 0;)
        {
            bool ok = false;
            while (j >= 0 && abs(a[x] - a[j]) <= dist)
                cnt++, j--, ok = true;
            dist++;

            x = j + 1;

            if (!ok)
                break;
        }

        ans = max(ans, cnt);
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