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
set <int> ndx;
int mem[N][3];

int dp (int i , int t)
{
    if (i == s.size())
        return 0;

    int &ret = mem[i][t];

    if (ret != -1)
        return ret;

    ret = 1e9;

    if (s[i] >= 'a')
    {
        if (t == 2)
        {
            ret = dp(i + 1 , 2) + 1;
        }
        else if (t == 0 && ndx.lower_bound(i) != ndx.end())
        {
            ret = min(dp(i + 1 , 2) + 1 , dp(i + 1 , 1));
        }
        else 
        {    
            ret = dp(i + 1 , 1);
        }
    }
    else
    {
        if (t == 1)
        {    
            ret = dp(i + 1 , 1) + 1;
        }
        else 
        {
            ret = dp(i + 1 , 0);
        }
    }

    return ret;
}

void solve()
{
    cin >> s;

    for (int i = 0 ; i < s.size() ; i ++)
        if (s[i] < 'a')
            ndx.insert(i);

    memset(mem , -1 , sizeof mem);

    cout << dp(0 , 0) << endl;
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