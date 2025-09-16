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
    int s;
    int i;
    bool shift;
};

bool operator<(const Event &a, const Event &b) { return a.s < b.s; }

void solve()
{
    int n;
    cin >> n;

    vector<Event> a;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        a.pb({l, i, false});
        a.pb({r, i, true});
    }

    int total = 0, prev = 0, ans = 0;

    sort(all(a));

    vector<int> alone_time(n, 0);
    set<int> turn;

    for (auto e : a)
    {
        int cur = e.s;

        if (turn.size())
            total += cur - prev;

        if (turn.size() == 1)
            alone_time[*turn.begin()] += cur - prev;

        if (e.shift)
            turn.erase(e.i);
        else
            turn.insert(e.i);

        prev = cur;
    }

    ans = total - *min_element(all(alone_time));

    cout << ans << endl;
}

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}