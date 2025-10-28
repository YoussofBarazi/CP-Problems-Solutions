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

bool cmp (array<ll , 4> a , array<ll , 4> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

void solve()
{
    ll n , k;
    cin >> n >> k;

    vector <int> a(n);

    for (auto &x : a)
        cin >> x;

    sort(all(a));

    n = unique(all(a)) - a.begin();

    vector <bool> used(n , false);
    vector <array<ll , 4>> q;

    for (int l = 0 ; l < n ; l ++)
    {
        for(int r = l + 1 ; r < n ; r ++)
        {
            ll sum = 0;

            for (int i = l ; i <= r ; i ++)
            {
                sum += a[i];
            }

            int cnt1 = 0 , cnt2 = 0;
            ll avg1 = sum / (r - l + 1) , avg2 = (sum + r - l) / (r - l + 1);
            ll cost1 = 0 , cost2 = 0;

            for (int i = l ; i <= r ; i ++)
            {
                cost1 += abs(avg1 - a[i]);
                cost2 += abs(avg2 - a[i]);
            }

            q.pb({r - l , cost1 , l , r});
            q.pb({r - l , cost2 , l , r});
        }
    }

    sort(allr(q) , cmp);

    int ans = n;

    for (auto x : q)
    {
        if (k < x[1] || used[x[2]] || used[x[3]])
            continue;

        k -= x[1];
        ans -= (x[3] - x[2]);

        for (int i = x[2] ; i <= x[3] ; i ++)
            used[i] = true;
    }

    cout << ans << endl;
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