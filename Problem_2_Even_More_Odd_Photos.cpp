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

    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        odd += x % 2;
    }

    int ans = 0;
    if (odd * 2 == n)
        ans = n;
    else if (odd * 2 < n)
        ans = odd * 2 + 1;
    else
    {
        ans = (n - odd) * 2;
        odd -= n - odd;

        ans += (odd / 3) * 2;
        odd %= 3;

        if (odd == 2)
            ans++;
        else if (odd == 1)
            ans--;
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