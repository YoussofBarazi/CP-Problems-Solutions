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

double eps = 1e-15;
int n, d, ansL = -1, ansR = -1;
vector<double> a;

bool ok(double avg)
{
    vector<double> sum(n + 1, 0), mn(n + 1, 0);
    vector<int> ndx(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = a[i] + sum[i] - avg;
    }

    int l = 0;
    ansL = -1, ansR = -1;

    for (int r = 1; r <= n; r++)
    {
        mn[r] = mn[r - 1];
        ndx[r] = ndx[r - 1];

        if (sum[r] < mn[r])
            mn[r] = sum[r], ndx[r] = r;

        if (r >= d)
        {
            l = r - d;

            if (sum[r] - mn[l] >= 0)
            {
                ansL = ndx[l], ansR = r;
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    cin >> n >> d;

    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    double l = 0.0, r = 100;

    for (int i = 0; i < 100; i++)
    {
        double m = (r + l) / 2;

        if (ok(m))
            l = m;
        else
            r = m;
    }

    ok(l);

    cout << ansL + 1 << " " << ansR << endl;
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