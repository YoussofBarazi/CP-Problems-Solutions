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

    if (n <= 3)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 2; i * i <= n - 2; i++)
    {
        if ((n - 2) % i == 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << 2 << " " << n - 2 << endl;
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