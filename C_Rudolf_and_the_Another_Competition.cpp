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
    int n, m, h;
    cin >> n >> m >> h;

    vector<pair<ll, ll>> res;
    pair<ll, ll> rudolf;

    for (int i = 0; i < n; i++)
    {
        vector<int> t(m);
        for (auto &x : t)
            cin >> x;

        sort(all(t));

        int time = 0;
        ll cnt = 0, penalty = 0;

        for (auto x : t)
        {
            time += x;
            if (time <= h)
            {
                penalty += time;
                cnt++;
            }
            else
                break;
        }

        if (i == 0)
        {
            rudolf = {cnt, penalty};
            continue;
        }

        res.pb({cnt, penalty});
    }

    int cnt = 0;
    for (auto x : res)
    {
        if (x.F > rudolf.F)
            cnt++;
        else if (x.F == rudolf.F && rudolf.S > x.S)
            cnt++;
    }

    cout << cnt + 1 << endl;
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