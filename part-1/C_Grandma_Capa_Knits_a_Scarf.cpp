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
    int n; string s;
    cin >> n >> s;

    set <char> c;
    for (size_t i = 0; i < n; i++)
    {
        c.insert(s[i]);
    }
    
    int ans = oo;
    for (auto a : c)
    {
        int i = 0 , j = n - 1;
        int cnt = 0;
        while (i <= j)
        {
            if (s[i] == s[j]) i ++ , j --;
            else if (s[i] == a) i ++ , cnt ++;
            else if (s[j] == a) j -- , cnt ++;
            else 
            {
                cnt = n + 1;
                break;
            }
        }
        ans = min(ans , cnt);
    }
    
    if (ans == n + 1) ans = -1;

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