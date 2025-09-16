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
    int n , k;
    cin >> n >> k;

    vi a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (!a[i][j] == a[n - i - 1][n - j - 1])
            {
                k --;
                a[i][j] = !a[i][j];
            }
        }
    }

    if (k < 0 || (n % 2 == 0 && k % 2))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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