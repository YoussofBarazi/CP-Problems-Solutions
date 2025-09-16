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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
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

    vi a(n + 1) , sum(n + 1 , 0);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    
    int l = 1 , r = n , m;
    while (l < r)
    {
        m = (l + r) / 2;

        cout << "? ";
        cout << m - l + 1 << " ";
        for (size_t i = l; i <= m; i++)
        {
            cout << i << " ";
        }
        cout << endl;

        int x;
        cin >> x;

        if (sum[m] - sum[l - 1] == x)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    cout << "! " << l << endl;
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