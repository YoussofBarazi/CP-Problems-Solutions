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
vi a;
int n, k;

bool ok(ll s)
{
    ll sum = 0;
    int cnt = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > s)
            return false;

        if (sum + a[i] > s)
        {
            cnt++;
            if (a[i] < s)
                sum = a[i];
            else
                sum = 0, cnt++;
        }
        else
        {
            sum += a[i];
        }
    }

    return cnt <= k;
}

void solve()
{
    scanf("%d %d", &n, &k);

    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    ll l = 1, r = 1e14;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;

        if (ok(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << r << endl;
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