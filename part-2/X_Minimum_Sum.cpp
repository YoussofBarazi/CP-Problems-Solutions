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

    vector<string> s(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int a[12], used[12];
    for (size_t i = 0; i < 12; i++)
    {
        a[i] = -1;
        used[i] = 0;
    }

    map<int, int> m;

    for (size_t i = 0; i < n; i++)
    {
        m[s[i][0] - 'a']++;
    }

    int x = 1;
    while (m.size())
    {
        int mx = 0, ind = 0;
        for (auto x : m)
        {
            if (x.S > mx)
            {
                mx = x.S;
                ind = x.F;
            }
        }
        a[ind] = x;
        used[x]++;
        m.erase(ind);
        x++;
    }
    int j = 1;
    while (j < 6)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (j < s[i].size())
            {
                m[s[i][j] - 'a'] ++;
            }
        }
        
        while (m.size())
        {
            int mx = 0, ind = 0;
            for (auto x : m)
            {
                if (x.S > mx)
                {
                    mx = x.S;
                    ind = x.F;
                }
            }
            
            int x = 0;
            while (x < 10 && used[x] > 0)
                x++;
            if (x < 10 && a[ind] == -1)
            {
                a[ind] = x;
                used[x]++;
            }
            m.erase(ind);
        }
        j ++;
    }

    ll ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x = 0;
        for (size_t j = 0; j < s[i].size(); j++)
        {
            x += a[s[i][j] - 'a'];
            if (j < s[i].size() - 1)
            {
                x *= 10;
            }
        }
        ans += x;
    }
    
    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}