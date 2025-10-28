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
int n;
int a[N];

bool ok(int m)
{
    int i = 0;
    while (i < n && a[i] - a[0] <= 2 * m)
        i++;

    int j = n - 1;
    while (j >= i && a[n - 1] - a[j] <= 2 * m)
        j--;

    while (i <= j && a[j] - a[i] <= 2 * m)
        i++;

    return i >= j;
}

void solve()
{
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
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