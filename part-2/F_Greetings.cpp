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

const int N = 400009;

int seg[4 * N];

void update(int p, int l, int r, int i)
{
    if (l == r)
    {
        seg[p] = 1;
        return;
    }

    int mid = l + (r - l) / 2;

    if (mid >= i)
        update(p * 2, l, mid, i);
    else
        update(p * 2 + 1, mid + 1, r, i);

    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int query(int p, int l, int r, int left, int right)
{
    if (l >= left && r <= right)
        return seg[p];

    if (l > right || r < left)
        return 0;

    int mid = l + (r - l) / 2;

    int sum = query(p * 2, l, mid, left, right);
    sum += query(p * 2 + 1, mid + 1, r, left, right);

    return sum;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a;
    vector<pair<int, int>> x;

    for (int i = 0 ; i <= 8 * n ; i ++)
        seg[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        a.pb(l), a.pb(r);
        x.push_back({l, r});
    }

    sort(all(a));

    ll ans = 0;

    vector <int> ww(a.size() , 0);

    int cnt = 0;
    for (auto p : x)
    {
        int ind1 = lower_bound(all(a), p.first) - a.begin();
        int ind2 = lower_bound(all(a), p.second) - a.begin();
        ww[ind1] = cnt , ww[ind2] = cnt;
        cnt ++;
    }   

    vector <int> left(n , 0);

    for (int i = 0 ; i < n * 2 ; i ++)
    {
        if (left[ww[i]] == 0)
            left[ww[i]] = i + 1;
        else 
        {
            ans += query(1, 1, n * 2, left[ww[i]], i + 1);
            update(1, 1, n * 2, left[ww[i]]);
        }
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