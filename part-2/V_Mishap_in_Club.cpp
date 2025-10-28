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

    int n = s.size() , cnt = 1 , ans = 0 , def = 1 , tmp , mn = 0;
    int i = 0;
    while (i < n)
    {
        while (i + 1 < n && s[i] == s[i + 1])
        {
            def ++;
            i ++;
        }
        ans = max(ans , def);
        def --;
        tmp = def;
        i ++;

        while (i + 1 < n && s[i] == s[i + 1])
        {
            def --;
            i ++;
        }
        if (def < 0)
            mn = min (mn , def);
        tmp = def;
        def ++;
        i ++;
    }
    
    cout << ans - mn << endl;
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