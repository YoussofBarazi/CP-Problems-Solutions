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
    int n , k;
    cin >> n >> k;

    vector <ll> a(n);
    int g = 0;
    for (auto &x : a)
    {
        cin >> x;
        g = gcd(g , x);
    }

    if (n > 1) for (auto &x : a) x %= g;

    sort(all(a));

    for (int i = 1 ; i < n ; i ++)
    {
        a[i] = a[i - 1] + g;
    }

    ll t = 0 , last = -1;

    for (int i = 0 ; i < n ; i ++)
    {
        if (a[i] - last + t - 1 < k)
        {
            t += a[i] - last - 1;
            last = a[i];
        }
        else 
        {
            cout << last + (k - t) << endl;
            return;
        }
    }

    cout << last + k - t << endl;
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