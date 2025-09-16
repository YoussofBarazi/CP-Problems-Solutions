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
    int n;
    cin >> n;

    map<string, vector<pair<int, int>>> schedule;
    while (n--)
    {
        int start, end, m;
        string contest;
        cin >> contest >> start >> end >> m;

        while (m--)
        {
            string name;
            cin >> name;

            schedule[name].pb({start, end});
        }
    }

    vector<string> ans;
    for (auto x : schedule)
    {
        vector<int> full(370, 0);

        for (auto y : x.S)
        {
            full[y.F]++;
            full[y.S + 1]--;
        }

        for (size_t i = 1; i < 370; i++)
        {
            full[i] += full[i - 1];

            if (full[i] >= 2)
            {
                ans.pb(x.F);
                break;
            }
        }
    }

    sort(all(ans));

    cout << ans.size() << endl;

    for (auto x : ans)
        cout << x << endl;
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