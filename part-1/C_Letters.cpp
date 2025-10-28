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
    int n , m;
    cin >> n >> m;

    vector <ll> sum(n + 1 , 0);
    for (int i = 1 ; i <= n ; i ++)
    {
        ll x;
        cin >> x;

        sum[i] = x + sum[i - 1];
    }

    while (m --)
    {
        ll x;
        cin >> x;

        int ndx = lower_bound(all(sum) , x) - sum.begin();
        cout << ndx << " " << x - sum[ndx - 1] << endl;
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