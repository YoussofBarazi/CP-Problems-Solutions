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

    set<pair<int, pair<int, int>>> event;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        event.insert({a, {0, i}});
        event.insert({b, {1, i}});
    }

    vector<int> ans(n, -1);
    set<int> free = {1};
    int cnt = 1;

    for (auto e : event)
    {
        if (e.S.F)
        {
            free.insert(ans[e.S.S]);
            continue;
        }

        if (!free.size())
        {
            cnt++;
            free.insert(cnt);
        }

        ans[e.S.S] = *free.begin();
        free.erase(free.begin());
    }

    cout << cnt << endl;

    for (auto x : ans)
        cout << x << " ";
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