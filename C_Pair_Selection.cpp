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

int n, k;
vector<pair<double, double>> a;

bool ok(double ans)
{
    vector<double> tmp(n);
    for (int i = 0; i < n; i++)
    {
        tmp[i] = a[i].F - a[i].S * ans;
    }

    sort(allrev(tmp));

    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tmp[i];
    }

    return sum >= 0;
}

void solve()
{
    cin >> n >> k;

    a.resize(n);
    for (auto &x : a)
        cin >> x.F >> x.S;

    double l = 0, r = 1e5;
    for (int i = 0; i < 100; i++)
    {
        double m = l + (r - l) / 2;

        if (ok(m))
            l = m;
        else
            r = m;
    }

    cout << fixed << setprecision(10);
    cout << l << endl;
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