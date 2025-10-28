#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    if (n == 2)
    {
        int ans = 10 * (s[0] - '0') + s[1] - '0';
        cout << ans << endl;
        return ;
    }
    if (s[0] == '0' || s.back() == '0')
    {
        cout << 0 << endl;
        return ;
    }

    bool one = false;
    int x = 100 , ndx;

    ll res = 1e18;

    for (int i = 0 ; i < n - 1 ; i ++)
    {    
        x = 10 * (s[i] - '0') + s[i + 1] - '0' , ndx = i;
        
        ll ans = x;
        
        if (ans == 0)
            res = 0;

        for (int i = 0 ; i < ndx ; i ++)
        {
            if (s[i] <= '1' || (i + 1 == ndx && x <= 1))
                ans *= (s[i] - '0');
            else 
                ans += (s[i] - '0');

            if (ans == 0)
                res = 0;
        }
        for (int i = ndx + 2 ; i < n ; i ++)
        {
            if (s[i] <= '1')
                ans *= (s[i] - '0');
            else 
            {
                if (x <= 1 && i == ndx + 2)
                {
                    ans *= (s[i] - '0');
                }
                else 
                {
                    ans += (s[i] - '0');
                }
            }

            if (ans == 0)
                res = 0;
        }

        res = min(res , ans);
    }

    // cout << ndx << endl;


    cout << res << endl;
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