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

const int N = 100009;

string s;
int k , n;

ll mem[31][N][26];
bool vis[31][N][26];

ll dp(int i , int cnt , char cur)
{
    if (i == n || cnt == 0)
        return 0;

    ll &ret = mem[i][cnt][cur - 'A'];

    if (vis[i][cnt][cur])
        return ret;

    vis[i][cnt][cur] = true;

    return ret = (cur != s[i]) + dp(i + 1 , cnt - 1 , s[i]) + dp(i + 1 , cnt , 'A');
}

void solve()
{
    cin >> s >> k;
    n = s.size();
    
    cout << dp(0 , min(k , N - 1) , 'A');
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