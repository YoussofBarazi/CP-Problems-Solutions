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
    ll n , s;
    cin >> n >> s;

    vector <ll> a(n);
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    ll sum = 0 , ans = 0;
    int j = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        while (j < n && sum + a[j] <= s)
        {
            sum += a[j];
            j ++;
        }

        ll cnt = j - i + 1;
        ans += (cnt - 1) * cnt / 2;

        sum -= a[i];
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