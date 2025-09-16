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
    int N, M, R;
    cin >> N >> M >> R;

    vector<ll> c(N), r(R);
    vector<pair<ll, ll>> q(M);

    for (auto &x : c)
        cin >> x;

    for (auto &x : q)
        cin >> x.S >> x.F;

    for (auto &x : r)
        cin >> x;

    sort(allrev(c));
    sort(allrev(q));
    sort(allrev(r));

    int l = 0 , h = N - 1 , j = 0, k = 0;
    ll gallons = 0, value = 0 ,ans = 0;

    while (l <= h)
    {
        while (j < M)
        {
            ll req = min(q[j].S , c[l] - gallons);

            gallons += req;
            value += q[j].F * req;

            q[j].S -= req;
            
            if (q[j].S > 0)
                break;

            j++;
        }

        if (k < R && value < r[k])
        {
            h --;
            ans += r[k ++];
        }
        else 
        {
            ans += value;
            value = 0;
            gallons = 0;
            l++;
        }
    }

    cout << ans << endl;
}

int main()
{
    freopen("rental.in" , "r" , stdin);
    freopen("rental.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}