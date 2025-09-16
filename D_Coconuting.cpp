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
    
    vector <int> a(n);
    map <ll , ll> freq;

    for (int &x : a)
    {
        cin >> x;
        freq[x] ++;
    }

    ll ans = 0;

    for (auto t : freq)
    {
        for (ll i = 2 ; i * i * i * t.F <= 1e11 ; i ++)
        {
            ll x = 1ll * i * i * i * t.F;

            if (freq.count(x))
                ans += t.S * freq[x];
        }

        ans += (t.S - 1) * t.S / 2;
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