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
    int n , m , k , w;
    cin >> n >> m >> k >> w;

    vector <int> a(w);
    for (auto &x : a)
        cin >> x;

    sort(allr(a));

    vector <int> v;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < m ; j ++)
        {
            int cnt = (min(i , n - k) - max(-1 , i - k)) * (min(j , m - k) - max(-1 , j - k));  
            // cout << cnt << " ";
            v.push_back(cnt);
        }
        // cout << endl;
    }

    sort(allr(v));

    ll ans = 0;

    for (int i = 0 ; i < w ; i ++)
    {
        ans += 1ll * a[i] * v[i];
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