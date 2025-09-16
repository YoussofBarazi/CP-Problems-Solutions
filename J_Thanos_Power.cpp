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

string s;
int mem[N][2];

int dp(int i , int d)
{
    if (i == s.size())
        return d * 2;

    int &ret = mem[i][d];

    if (ret != -1)
        return ret;

    int t = s[i] - '0';

    ret = min(dp(i + 1 , 0) + 11 - t + d * 2 , dp(i + 1 , 0) + t + d * 2);
    ret = min(ret , dp(i + 1 , 1) + 10 - t - 1);

    return ret;
}

void solve()
{
    cin >> s;

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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}