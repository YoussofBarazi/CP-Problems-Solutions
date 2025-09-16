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
    string s;
    cin >> s;

    map <char , int> m;
    int mx = 0;
    for (size_t i = 0; i < 4; i++)
    {
        m[s[i]] ++;
        mx = max(mx , m[s[i]]);
    }
    
    int ans = -1;
    if (m.size() >= 3)
        ans = 4;
    else if (m.size() == 2)
        if (mx == 2)
            ans = 4;
        else 
            ans = 6;

    cout << ans << endl;
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