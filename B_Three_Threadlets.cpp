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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    int cuts = (a[2]) / a[0] + (a[1]) / a[0] - 2;

    if (a[2] % a[0] || a[1] % a[0])
        cuts = 4;

    if (cuts <= 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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