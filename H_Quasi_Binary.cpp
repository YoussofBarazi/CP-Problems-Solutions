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

const int N = 1000009;

vector<int> x;
vector<bool> exist(N, false);
int mem[N];
int n;

int dp(int sum)
{
    int &ret = mem[sum];

    if (sum == 0)
        return ret = 0;

    if (ret != -1)
        return ret;

    ret = 1e6;

    for (int i = 0; i < x.size(); i++)
    {
        if (sum >= x[i]) ret = min(dp(sum - x[i]) + 1, ret);
    }

    return ret;
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);

        bool ok = true;

        for (int i = 0; i < s.size(); i++)
            if (s[i] > '1')
                ok = false;

        if (ok)
            x.push_back(i), exist[i] = true;
    }

    memset(mem, -1, sizeof mem);

    int cnt = dp(n);

    cout << cnt << endl;

    cnt--;

    for (int i = n ; i >= 0; i--)
    {
        if ((mem[i] == cnt) && exist[n - i])
        {
            cout << n - i << " ";
            n = i;
            cnt--;
        }
    }
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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}