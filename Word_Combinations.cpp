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

vector<ll> pre1(N) , p1(N);
ll base = 29;

ll calc(string s)
{
    pre1[0] = 0, p1[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p1[i] = p1[i - 1] * base;

        pre1[i] = pre1[i - 1] * base + s[i] - 'A' + 1;
    }

    return pre1[s.size() - 1];
}

ll get_ans(int l, int r)
{
    ll x = (pre1[r] - pre1[l - 1] * p1[r - l + 1]);
  
    return x;
}


string s;
map <ll , bool> exist;
int DP[5009] , mod = 1e9 + 7;

int dp(int left)
{
    if (left == s.size())
        return 1;

    int &ret = DP[left];

    if (ret != -1)
        return ret;

    ret = 0;
    string t = "";

    for (int right = left ; right < s.size() ; right ++)
    {
        t += s[right];

        if (exist.count(get_ans(left , right)))
        {    
            ret += dp(right + 1);
            if (ret >= mod)
                ret -= mod;
        }
    }

    return ret;
}

void solve()
{
    int k;
    cin >> s >> k;

    for (int i = 0 ; i < k ; i ++)
    {
        string t;
        cin >> t;

        exist[calc('#' + t)] = true;
    }

    s = '#' + s;
    calc(s);

    memset(DP , -1 , sizeof DP);

    cout << dp(1) << endl;
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