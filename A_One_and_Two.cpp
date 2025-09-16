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

    vl a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int x1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 2) x1 ++;
        int x2 = 0;
        for (size_t j = i + 1; j < n; j++)
        {
            if (a[j] == 2) x2 ++;
        }
        
        if (x1 == x2)
        {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
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