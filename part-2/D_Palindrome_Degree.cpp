#include <bits/stdc++.h>

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

const int N = 5000009;

vector<ll> pre(N), p(N);
ll base = 29;

vector<ll> calc_hash(string s)
{
    pre[0] = 0, p[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p[i] = p[i - 1] * base;
        pre[i] = pre[i - 1] * base + s[i] - 'a' + 1;
    }

    return pre;
}

ll sub_hash(int l, int r , vector <ll> &pre)
{
    ll x = (pre[r] - pre[l - 1] * p[r - l + 1]);

    return x;
}

void solve()
{
    string s , t;
    cin >> s;

    t = s;
    reverse(all(t));

    t = '*' + t;
    s = '*' + s;

    vector <ll> T = calc_hash(t);
    vector <ll> S = calc_hash(s);

    int ans = 0;
    vector <int> lvl(s.size() , 0);

    for (int i = 1 ; i < s.size() ; i ++)
    {
        if (sub_hash(1 , i , S) != sub_hash(s.size() - i , s.size() - 1 , T))
            continue;

        int half = i / 2;

        lvl[i] = lvl[half] + 1;
        ans += lvl[i];
    }

    cout << ans << endl;
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