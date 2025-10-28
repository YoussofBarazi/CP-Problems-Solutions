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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int K = 5009;

int n , k;
int freq[26];
ll DP[K][26];

ll calc(int v , ll sz)
{
    v += 'a';
    return sz * (sz - 1) * v / 2;
}

int c1 , c2;

ll dp(int i , int c)
{
    if (c >= 26) 
    {
        int t = min(i , freq[c2]);

        return calc(c1 , freq[c1] + k - i + t) + calc(c2 , freq[c2] - t);
    }

    ll &ret = DP[i][c];

    if (ret != -1) return ret;

    if (c == c1 || c == c2) return ret = dp(i , c + 1);

    int t = freq[c];

    ret = dp(i , c + 1) + calc(c , t);

    if (t <= i)
    {
        ret = max(ret , dp(i - t , c + 1));
    }

    return ret;
}

void solve()
{
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0 ; i < 26 ; i ++)
        freq[i] = 0;

    for (int i = 0 ; i <= k ; i ++)
        for (int j = 0 ; j < 26 ; j ++)
            DP[i][j] = -1;

    for (int i = 0 ; i < n ; i ++)
    {
        freq[s[i] - 'a'] ++;
    }

    ll ans = 0;

    for (int i = 0 ; i < 26 ; i ++)
    {
        for (int j = 0 ; j < 26 ; j ++)
        {       
            if (i == j)
                continue;
            
            memset(DP , -1 , sizeof DP);

            c1 = i , c2 = j;
            ans = max(ans , dp(k , 0));
        }
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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