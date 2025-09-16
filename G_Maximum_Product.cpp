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

ll DP[20][2][2][2];
string a , b;
 
ll dp(int i = 0 , bool leading_zeroes = true , bool f1 = true , bool f2 = true) {
    
    if (i == b.size()) {
        return 1;
    }

    ll &ret = DP[i][leading_zeroes][f1][f2];
    
    if (ret != -1) return ret;

    int l = (!f1)? 0 : (a[i] - '0');
    int r = (!f2)? 9 : (b[i] - '0');

    for (int d = r ; d >= l ; d --) {

        ret = max(ret , (leading_zeroes && d == 0 ? 1 : d) * dp(i + 1 , leading_zeroes & (d == 0) , f1 & (d == l) , f2 & (d == r)));
    }

    return ret;
}

ll ans = 0;

void DFS(int i = 0 , bool leading_zeroes = true , bool f1 = true , bool f2 = true) {
    
    if (i == b.size()) return;
    
    int l = (!f1)? 0 : (a[i] - '0');
    int r = (!f2)? 9 : (b[i] - '0');

    ll mx = -1;
    array <ll , 5> state;

    for (int d = r ; d >= l ; d --) {

        ll cur = (leading_zeroes && d == 0 ? 1 : d) * dp(i + 1 , leading_zeroes & (d == 0) , f1 & (d == l) , f2 & (d == r));
        if (mx < cur)
            mx = cur , state = {d , i + 1 , leading_zeroes & (d == 0) , f1 & (d == l) , f2 & (d == r)};   
    }

    ans = ans * 10 + state[0];
    DFS(state[1] , state[2] , state[3] , state[4]);    
}

void solve()
{
    cin >> a >> b;

    if (a.size() < b.size()) a = string(b.size() - a.size() , '0') + a;

    memset(DP , -1 , sizeof DP);

    DFS();

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