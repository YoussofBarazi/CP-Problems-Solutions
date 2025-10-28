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

const int N = 100001 , M = 100;

int n;
int a[M] , mem[M][N];
bool vis[M][N];

int dp(int i , int x)
{
    if (i == -1)
        return 0;

    int &ret = mem[i][x];

    if (vis[i][x])
        return ret;
    
    vis[i][x] = true;

    if (x - a[i] >= 0)
        ret = max(dp(i - 1 , x - a[i]) + a[i] , dp(i - 1 , x));
    else
        ret = dp(i - 1 , x);

    return ret;
}

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    for (int x = 0 ; x < N ; x ++)
        dp(n - 1 , x);

    vector <bool> exist(N , false);
    vector <int> ans ;
    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < N ; j ++)
            if (!exist[mem[i][j]] && mem[i][j])
            {
                exist[mem[i][j]] = true;
                ans.pb(mem[i][j]);
            }
    }

    sort(all(ans));

    cout << ans.size() << endl;

    for (int s : ans)
        cout << s << " ";
    cout << endl;
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