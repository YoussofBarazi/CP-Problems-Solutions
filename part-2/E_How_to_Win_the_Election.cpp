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

ll sum[N];
pair<ll , ll> a[N];
ll A[N];
int n , m;
ll k;

bool ok(ll x , int i)
{
    ll cur_votes = a[i].F + x; //4
    ll rvotes = k - x; // 6
    int ndx = upper_bound(A , A + n + 1 , cur_votes) - A; // 2

    if (n - m + 1 >= ndx) return false; // 12

    int cmpt = m - (n - ndx + 1); // 1
    int least_cmpt = ndx - cmpt; // 1
    if (cmpt == 0 || least_cmpt == 1) return true;

    ll votes = sum[ndx - 1] - sum[least_cmpt - 1]; // 81
    
    if (least_cmpt <= i) {
        votes -= a[i].F;
        votes += a[least_cmpt - 1].F;
    }

    // cout << m << " " << n << " " << ndx << endl;

    ll t = (votes + rvotes) / (cmpt); // 4

    // if (x == 0 && i == 4)
    //     cout << cur_votes << " " << ndx << " " << sum[least_cmpt - 1] << endl;

    return t <= cur_votes;
}

void solve()
{
    cin >> n >> m >> k;

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i].F;
        a[i].S = i;    
        A[i] = a[i].F;
    }

    sort(a , a + n + 1);
    sort(A , A + n + 1);
    vector <ll> ans(n);

    for (int i = 1 ; i <= n ; i ++)
    {
        sum[i] = sum[i - 1] + A[i];
    }

    k -= sum[n];

    for (int i = 1 ; i <= n ; i ++)
    {
        ll l = 0 , r = k;

        while (l < r)
        {
            ll mid = (l + r) / 2;

            if (ok(mid , i)) r = mid;
            else l = mid + 1;
        }

        ans[a[i].S - 1] = ok(l , i) ? l : -1;
    }
    // cout << A[3] << endl;
    // for (int i = 0 ; i <= k ; i ++)
    //     cout << ok(i , 1) << " ";
    //     cout << endl;
    for (auto x : ans) cout << x << " ";
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