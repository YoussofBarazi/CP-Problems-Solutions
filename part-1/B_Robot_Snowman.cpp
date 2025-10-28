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

double n;

bool ok(double m)
{
    double body = 5 * m;
    double torso = 3 * m;
    double head = m;

    body *= body * body;
    torso *= torso * torso;
    head *= m * m;

    double all = body + torso + head;

    return n - all >= 0;
}

void solve()
{
    cin >> n;

    double l = 0, r = sqrt(n), m;

    for (int i = 0; i < 100; i++)
    {
        m = (r + l) / 2;

        if (ok(m))
            l = m;
        else
            r = m;
    }

    cout << fixed << setprecision(10);
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