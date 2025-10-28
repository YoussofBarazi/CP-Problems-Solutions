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

vector<ll> pre(N), p(N);
map <char , int> val;
ll base = 257;

ll calc(string s)
{
    pre[0] = 0, p[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p[i] = p[i - 1] * base;
        pre[i] = pre[i - 1] * base + s[i] ;
    }

    return pre[s.size() - 1];
}

ll get_ans(int l, int r , vector <ll> &pre)
{
    ll x = (pre[r] - pre[l - 1] * p[r - l + 1]);

    return x;
}

bool ok(int sz , int mini , vector <ll> &text , vector <ll> &pattern)
{
    ll prefix = get_ans(1 , sz , pattern);
    int cnt = 0;

    for (int i = sz ; i < text.size() ; i ++)
    {
        if (prefix == get_ans(i - sz + 1 , i , text))
            cnt ++;
    }

    //cout << sz << " " << cnt << endl;

    return cnt >= mini;
}

void solve()
{
    int m;
    string t , p;
    getline(cin , t);
    getline(cin , p);
    cin >> m;

    t = '*' + t;
    p = '*' + p;
    calc(t);
    vector <ll> text = pre;
    calc(p);
    vector <ll> pattern = pre;

    int l = 0 , r = p.size() - 1;
    
    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        if (ok(mid , m , text , pattern))
            l = mid;
        else 
            r = mid - 1;
    }

    string ans = "";

    for (int i = 1 ; i <= l ; i ++)
        ans += p[i];

    if (ans == "")
        cout << "IMPOSSIBLE" << endl;
    else 
        cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}