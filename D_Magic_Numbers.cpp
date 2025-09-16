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

const int N = 2009;

int DP[N][N][2];
string a , b;
int d , m , mod = 1e9 + 7 , t = 0;

int dp(string &s , int i = 0 , int num = 0 , bool f = true) {

    if (i == s.size()) return (num == 0) && ((t == 1) ? !f : 1);

    int &ret = DP[i][num][f];
    
    if (ret != -1) return ret;

    int r = !f ? 9 : (s[i] - '0');
    ret = 0;

    if (i % 2) {
        return ret = (d <= r) ? dp(s , i + 1 , (num * 10 + d) % m , f & (d == r)) : 0;        
    }

    for (int t = 0 ; t <= r ; t ++) {
        if (t == d) continue;
        ret += dp(s , i + 1 , (num * 10 + t) % m , f & (t == r));
        ret %= mod;
    }

    return ret;
}

void solve()
{
    cin >> m >> d >> a >> b;

    memset(DP , -1 , sizeof DP);

    int ans = dp(b) + mod;
    
    t = 1;
    memset(DP , -1 , sizeof DP);
    
    ans -= dp(a);

    cout << ans % mod << endl;
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