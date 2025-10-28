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



void solve()
{
    int n;
    cin >> n;

    vector <int> cnt1(n + 1 , 0) , cnt0(n + 1 , 0);
    int sum0 = 0 , sum1 = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        int x , y;
        cin >> x >> y;

        if (y == 1)
            cnt1[x] ++ , sum1 ++;
        else 
            cnt0[x] ++ , sum0 ++;
    }

    ll ans = 0;

    for (int x = 0 ; x <= n ; x++)
    {
        ans += 1ll * (sum0 - 1) * cnt1[x] * (cnt0[x] > 0);
    }
    for (int x = 0 ; x <= n ; x++)
    {
        ans += 1ll * (sum1 - 1) * cnt0[x] * (cnt1[x] > 0);
    }
    for (int x = 1 ; x < n ; x++)
    {
        ans += 1ll * cnt1[x] * cnt0[x - 1] * cnt0[x + 1];
    }
    for (int x = 1 ; x < n ; x++)
    {
        ans += 1ll * cnt0[x] * cnt1[x - 1] * cnt1[x + 1];
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