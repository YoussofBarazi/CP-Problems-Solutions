#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector <int> pref(N);

ll calc(ll x , ll len)
{
    ll cnt = x / len;

    return pref[len] * cnt + pref[x % len];
}

void solve()
{
    int a , b , n;
    cin >> a >> b >> n;
    
    int len = lcm(a , b);
    
    pref[0] = 0;
    for (int i = 1 ; i <= len ; i ++)
    {
        pref[i] = pref[i - 1];
        if ((i % a) % b != (i % b) % a)
        {
            pref[i]++;
        }
    }

    while (n --)
    {
        ll l , r;
        cin >> l >> r;

        cout << calc(r , len) - calc(l - 1 , len) << " ";
    }
    cout << endl;
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