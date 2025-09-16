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

struct Event
{
    int id, day, val;

    bool operator<(Event a)
    {
        return a.day > day;
    }
};

void solve()
{
    ll n, g;
    cin >> n >> g;

    vector<Event> e(n);

    map<int, ll> cow;
    map<ll, int> cnt;

    for (auto &x : e)
    {
        cin >> x.day >> x.id >> x.val;

        cow[x.id] = g;
        cnt[g]++;
    }

    sort(all(e));
    int ans = 0;

    for (auto x : e)
    {
        auto w = cnt.rbegin();

        bool was_top = w -> F == cow[x.id];
        ll prev_count = cnt[cow[x.id]];
        cnt[cow[x.id]]--;

        if (cnt[cow[x.id]] == 0)
        {
            cnt.erase(cow[x.id]);
        }

        cow[x.id] += x.val;
        cnt[cow[x.id]]++;

        w = cnt.rbegin();

        bool is_top = w -> F == cow[x.id];

        if (was_top)
        {
            if (is_top && prev_count == w -> S) continue;

            ans++;
        }
        else if (is_top)
            ans ++;
    }

    cout << ans << endl;
}

int main()
{
    freopen("measurement.in" , "r" , stdin);
    freopen("measurement.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}