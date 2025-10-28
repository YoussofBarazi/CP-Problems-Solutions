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
    int n , x;
    cin >> n >> x;

    vector <ll> sum(n + 2 , 0);

    for (int i = 1 ; i <= n ; i ++)
    {
        int t;
        cin >> t;

        sum[i] = sum[i - 1] + t;
    }

    int r = 1 , ans = 0;

    for (int l = 0 ; l <= n ; l ++)
    {
        while (r <= n && sum[r] - sum[l] < x)
            r ++;

        if (sum[r] - sum[l] == x)
        {
            ans ++;
        }
    }

    cout << ans << endl;
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