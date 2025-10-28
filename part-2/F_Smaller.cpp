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
    int q;
    cin >> q;

    map <int , ll> freq1 , freq2;

    freq1['a'] ++;
    freq2['a'] ++;

    while (q --)
    {
        int t , k; string s;
        cin >> t >> k >> s;

        if (t == 1)
        {
            for (auto x : s)
                freq1[x] += k;
        }
        else 
        {
            for (auto x : s)
                freq2[x] += k;
        }

        string ans = "NO";

        bool ok = false;

        for (auto x : freq1)
        {
            for (auto y : freq2)
            {
                if (x.F < y.F || (x.F == y.F && x.S < y.S && freq2.size() > 1))
                {
                    ans = "YES";
                    ok = true;
                    break;
                }
            }

            if (ok) break;
        }

        if (freq1.size() == 1 && freq2.size() == 1)
        {
            if (freq1.begin()->F == freq2.begin()->F && freq1.begin()->S < freq2.begin()->S)
                ans = "YES";
        }

        cout << ans << endl;
    }
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