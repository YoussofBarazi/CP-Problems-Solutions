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

const int N = 5009;

vector<ll> pre(N), p(N);
ll base = 29;

vector<ll> calc(string s)
{
    pre[0] = 0, p[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p[i] = p[i - 1] * base;
        pre[i] = pre[i - 1] * base + s[i] - 'a' + 1;
    }

    return pre;
}

ll get_ans(int l, int r , vector <ll> &pre)
{
    ll x = (pre[r] - pre[l - 1] * p[r - l + 1]);

    return x;
}

string s , t;
vector <ll> S , T;
int level;
int mem[N][N];
bool vis[N][N];

int k(int l , int r)
{
    if (vis[l][r])
        return mem[l][r];

    int half = (r - l + 1) / 2 - 1;

    if (half < 0) 
    {
        return 1;
    }
    if (get_ans(l , l + half , S) != 
        get_ans(s.size() - r  , s.size() - (r - half) , T))
    {
        return 0;
    }

    vis[l][r] = true;
    k(r - half , r);
    return mem[l][r] = k(l , l + half) + 1;
}

void solve()
{
    cin >> s;

    t = s;
    reverse(all(t));

    t = '*' + t;
    s = '*' + s;

    S = calc(s) , T = calc(t);
    vector <int> ans(s.size() + 2 , 0);

    for (int l = 1 ; l < s.size() ; l ++)
    {
        for (int r = l; r < s.size() ; r ++)
        {
            if (get_ans(l , r , S) != get_ans(s.size() - r , s.size() - l , T))
                continue;
            
            level = k(l , r);

            ans[1] ++ , ans[level + 1] --;
        }
    }

    for (int i = 1 ; i < s.size() ; i ++)  
    {
        ans[i] += ans[i - 1];    
    }
    for (int i = 1 ; i < s.size() ; i ++)  
    {
        cout << ans[i] << " ";
    }
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