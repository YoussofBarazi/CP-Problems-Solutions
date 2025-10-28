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
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (abs(a[i] - a[i + 1]) > m)
            if (a[i] < a[i + 1])
                a[i] = a[i + 1] - m;
            else
                a[i + 1] = a[i] - m;
    }

    for (int i = n; i >= 1; i--)
    {
        if (abs(a[i] - a[i - 1]) > m)
            if (a[i] < a[i - 1])
                a[i] = a[i - 1] - m;
            else
                a[i - 1] = a[i] - m;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    cout << endl;
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