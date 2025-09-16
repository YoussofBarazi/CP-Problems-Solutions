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

void solve()
{
    int n;
    cin >> n;

    vl a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    int cnt = 1;
    ll GCD = 0, LCM = 1;

    for (int i = 0; i < n; i++)
    {
        GCD = gcd(GCD, a[i] * b[i]);
        LCM = lcm(LCM, b[i]);

        if (GCD % LCM == 0)
            continue;

        cnt++;

        GCD = a[i] * b[i];
        LCM = b[i];
    }

    cout << cnt << endl;
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