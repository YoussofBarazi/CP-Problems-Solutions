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
    int n , m;
    cin >> n >> m;

    int even1 = 0 , odd1 = 0 , even2 = 0 , odd2 = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        even1 += x % 2 == 0;
        odd1 += x % 2;
    }
    for (size_t i = 0; i < m; i++)
    {
        int x; 
        cin >> x;

        even2 += x % 2 == 0;
        odd2 += x % 2;
    }
    
    cout << min(odd1 , even2) + min(odd2 , even1) << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}