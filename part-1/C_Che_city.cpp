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
    int n , r;
    cin >> n >> r;

    vector <int> a(n);
    for (auto &x : a)
        cin >> x;

    sort(all(a));

    ll j = 0 , ans = 0;
    for (ll i = 0 ; i < n ;i++)
    {
        while (j < n && a[j] - a[i] <= r)
            j ++;

        if (j < n)
            ans += n - j;
        else 
            break;
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