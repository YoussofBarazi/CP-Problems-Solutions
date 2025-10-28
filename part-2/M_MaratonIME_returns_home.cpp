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
    int n , m;
    cin >> n >> m;

    string s;
    int ans = 0 , money = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> s;

        if (i % 2 == 0)
            for (size_t i = 0; i < m; i++)
            {
                money += s[i] == '.';
                money *= !(s[i] == 'L');
                ans = max(ans , money);
            }
        else 
            for (int i = m - 1; i >= 0; i--)
            {
                money += s[i] == '.';
                money *= !(s[i] == 'L');
                ans = max(ans , money);
            }
    }
    
    cout << ans << endl;
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