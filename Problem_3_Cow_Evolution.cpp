#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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
    int n;
    cin >> n;

    map<string, set<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            string s;
            cin >> s;

            adj[s].insert(i);
        }
    }

    for (auto x : adj)
    {
        for (auto y : adj)
        {
            int cnt = 0;
            for (auto z : adj[x.F])
            {
                if (y.S.count(z))
                    cnt++;
            }

            if (cnt < min((int)x.S.size(), (int)y.S.size()) && cnt > 0)
            {
                cout << "no" << endl;
                return;
            }
        }
    }

    cout << "yes" << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}