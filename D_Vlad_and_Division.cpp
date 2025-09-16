#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
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

    vector<ll> a(n), vis(n, false);
    map<int, vector<int>> m;
    
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        m[a[i]].pb(i);
    }

    int ans = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        if (vis[i])
            continue;

        ll num = 0;
        
        for (int j = 0 ; j < 31 ; j ++)
        {
            if (bool(a[i] & (1 << j)))
            {
                continue;
            }
            
            num |= (1 << j);
        }
        
        //cout << num << endl;

        if (m[num].size())
        {
            vis[m[num].back()] = true;
            m[num].pop_back();
        }

        ans ++;
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}