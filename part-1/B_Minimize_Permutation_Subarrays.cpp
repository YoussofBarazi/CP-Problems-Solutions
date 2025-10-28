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

    vi a(n + 1);
    int ind1 = 0, ind2 = 0, indn;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (a[i] == 1)
            ind1 = i;
        else if (a[i] == 2)
            ind2 = i;
        else if (a[i] == n)
            indn = i;
    }

    if (ind2 < indn && ind1 > indn)
        cout << ind1 << " " << ind1 << endl;
    else if (ind2 > indn && ind1 < indn)
        cout << ind1 << " " << ind1 << endl;
    else if ((indn < ind1 && ind1 < ind2) || (indn > ind1 && ind1 > ind2))
        cout << ind1 << " " << indn << endl;
    else if ((indn > ind2 && ind2 > ind1) || (indn < ind2 && ind2 < ind1))
        cout << ind2 << " " << indn << endl;
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