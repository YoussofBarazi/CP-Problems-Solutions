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

struct query
{
    int l, r, v;

    query(int L, int R, int V)
    {
        l = L, r = R, v = V;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> ind;
    map<int, int> newInd;
    vector<query> add, print;
    vector<int> s(12, 0);

    for (int i = 0; i < n; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;

        s[l] += v;
        s[r] -= v;

        ind.push_back(l);
        ind.push_back(r);
        add.push_back(query(l, r, v));
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        ind.push_back(l);
        ind.push_back(r);
        print.push_back(query(l, r, 0));
    }

    sort(all(ind));
    ind.erase(unique(all(ind)), ind.end());

    for (auto q : add)
    {
        int i = lower_bound(all(ind), q.l) - ind.begin();
        newInd[q.l] = i;

        i = lower_bound(all(ind), q.r) - ind.begin();
        newInd[q.r] = i;
    }

    for (auto q : print)
    {
        int i = lower_bound(all(ind), q.l) - ind.begin();
        newInd[q.l] = i;

        i = lower_bound(all(ind), q.r) - ind.begin();
        newInd[q.r] = i;
    }

    vector<ll> sum(2 * (n + q) + 1, 0);
    vector<ll> range = sum, width = sum;

    for (auto q : add)
    {
        sum[newInd[q.l] + 1] += q.v;
        sum[newInd[q.r] + 1] -= q.v;
    }

    for (int i = 0; i < width.size() - 1; i++)
    {
        width[i + 1] = ind[i + 1] - ind[i];
    }

    for (int i = 1; i < range.size(); i++)
    {
        range[i] = range[i - 1] + sum[i];
    }

    for (int i = 1; i < sum.size(); i++)
    {
        sum[i] = sum[i - 1] + range[i] * width[i];
    }

    for (auto q : print)
    {
        ll ans = sum[newInd[q.r]] - sum[newInd[q.l]];

        cout << ans << endl;
    }
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