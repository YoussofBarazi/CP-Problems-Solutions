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

int n , k , a[109];
bool dp[N];
bool vis[N];

bool f(int cnt)
{
    if (cnt == 0)
        return false;

    if (vis[cnt])
        return dp[cnt];
    
    vis[cnt] = true;

    for (int i = 0 ; i < n ; i ++)
    {
        if (cnt - a[i] >= 0)
            dp[cnt] |= f(cnt - a[i]) ^ 1;
    }

    return dp[cnt];
}

void solve()
{
    cin >> n >> k;
    
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];
    
    cout << ((f(k)) ? "First" : "Second") << endl;    
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    
    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
    
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}