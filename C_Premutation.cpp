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

    vi a[n];
    for (size_t i = 0; i < n; i++)
    {
        a[i].resize(n);
        for (size_t j = 0; j < n - 1; j++)
        {
            cin >> a[i][j];   
        }
    }
    
    set <int> used;
    for (size_t i = 0; i < n - 1; i++)
    {
        int mn = 1e9 , mx = 0;
        map <int , int> m;
        for (size_t j = 0; j < n; j++)
        {
            m[a[j][i]] ++;
            mx = max(a[j][i] , mx);
            mn = min(a[j][i] , mn);
        }

        if (m[mx] > m[mn])
        {
            if (used.find(mx) == used.end()) cout << mx << " ";
            if (used.find(mn) == used.end()) cout << mn << " ";
            used.insert(mx);
            used.insert(mn);
        }
        else 
        {
            if (used.find(mn) == used.end()) cout << mn << " ";
            if (used.find(mx) == used.end()) cout << mx << " ";
            used.insert(mx);
            used.insert(mn);
        }
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