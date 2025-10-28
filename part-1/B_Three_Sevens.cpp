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
    int m;
    cin >> m;

    map <int , int> s;
    for (int day = 1; day <= m; day++)
    {
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            s[x] = max(s[x] , day);
        }
    }
    
    vi ans(m + 1 , -1);
    for (auto x : s)
    {
        ans[x.S] = x.F;
    }

    for (size_t i = 1; i <= m; i++)
    {
        if (ans[i] == -1)
        {
            cout << -1 << endl;
            return;
        }
    }
    
    for (size_t i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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