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

const int N = 1009;

int n , m , x , y;
vector <int> cnt_white(N , 0);
int DP[N][N][2];

int dp(int c , int cont , bool white)
{       
    if (cont > y)
        return 1e6;

    if (c == m)
        if (cont < x)
            return 1e6;
        else 
            return 0;

    int &ret = DP[c][cont][white];

    if (ret != -1)
        return ret;
    
    int ans1 = 1e6 , ans2 = 1e6;

    if (cont < x)
    {   
        if (white) 
            ans1 = dp(c + 1 , cont + 1 , true) + n - cnt_white[c];
        else
            ans2 = dp(c + 1 , cont + 1 , false) + cnt_white[c];
    }
    else 
    {
        ans1 = dp(c + 1 , ((white)? cont + 1 : 1) , true) + n - cnt_white[c];
        ans2 = dp(c + 1 , ((white)? 1 : cont + 1) , false) + cnt_white[c];
    }

    return ret = min(ans1 , ans2);
}

void solve()
{
    cin >> n >> m >> x >> y;

    for (int i = 0 ; i < n ; i ++)
    {
        string s;
        cin >> s;

        for (int j = 0 ; j < m ; j ++)
        {
            if (s[j] == '.')
                cnt_white[j] ++;
        }
    }

    memset(DP , -1 , sizeof DP);

    cout << min(dp(0 , 0 , 0) , dp(0 , 0 , 1)) << endl;
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