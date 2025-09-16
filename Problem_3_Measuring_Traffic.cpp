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

    vector<string> s(n);
    vector<int> u(n), l(n);

    for (int i = 0; i < n; i++)
        cin >> s[i] >> l[i] >> u[i];

    int a = -1e9, b = 1e9;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == "none")
            a = max(l[i], a), b = min(u[i], b);
        else if (s[i] == "on")
            a -= u[i], b -= l[i], a = max(a, 0);
        else
            a += l[i], b += u[i];
    }

    cout << a << " " << b << endl;

    a = -1e9, b = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == "none")
            a = max({l[i], a, 0}), b = min(u[i], b);
        else if (s[i] == "on")
            a += l[i], b += u[i];
        else
            a -= u[i], b -= l[i], a = max(a, 0);
    }

    cout << a << " " << b << endl;
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