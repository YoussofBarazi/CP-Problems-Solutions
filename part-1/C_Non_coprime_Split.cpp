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

const int N = 10000009;

int d[N];

void get()
{
    for (int i = 2; i < N; i++)
    {
        if (d[i] == 0)
            for (int j = i; j < N; j += i)
                d[j] = i;
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        if (i - d[i] > 1)
        {
            cout << d[i] << " " << i - d[i] << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    IOS;
    get();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}