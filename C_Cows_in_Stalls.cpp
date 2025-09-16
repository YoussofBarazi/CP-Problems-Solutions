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
int n, k;
vi a;

bool ok(int m)
{
    int cnt = 1;
    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (a[j] - a[i] >= m)
        {
            i = j;
            cnt++;
        }
    }

    return k <= cnt;
}

void solve()
{
    scanf("%d %d", &n, &k);

    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(all(a));

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + (r - l + 1) / 2;

        if (ok(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d", l);
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