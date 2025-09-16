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

ll DP[20][11][2][2];
string a , b;
 
ll dp(string &s , int i = 0 , int last = 10 , bool leading_zeroes = true , bool f = true) {
    
    if (i == s.size()) {
        return 1;
    }

    ll &ret = DP[i][last][leading_zeroes][f];
    
    if (ret != -1) return ret;

    int r = (!f)? 9 : (s[i] - '0');

    ret = 0;

    for (int d = r ; d >= 0 ; d --) {
       
        if (d == last && !leading_zeroes) continue;
        
        ret += dp(s , i + 1 , d , leading_zeroes & (d == 0) , f & (d == r));
    }

    return ret;
}

void solve()
{
    ll x , y;
    cin >> x >> y;

    a = to_string(x - 1) , b = to_string(y);

    if (a.size() < b.size()) a = string(b.size() - a.size() , '0') + a;

    memset(DP , -1 , sizeof DP);

    ll ans = dp(b);

    memset(DP , -1 , sizeof DP);
    
    if (x > 0) ans -= dp(a);

    cout << ans;
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