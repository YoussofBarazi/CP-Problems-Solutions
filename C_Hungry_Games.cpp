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

ll DP[N];
int n , x;

void solve()
{
    cin >> n >> x;

    vector <ll> a(n + 1 , 0);

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        DP[i] = 0;
    }

    DP[0] = DP[n + 1] = 0;

    ll ans = 0;

    for (int i = n - 1 ; i >= 0 ; i --)
    {
        int j = upper_bound(all(a) , a[i] + x) - a.begin();

        DP[i] = DP[j] + j - i - 1;
        ans += DP[i];
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