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

const int N = 5000009;

vector<ll> pre(N), p(N);
ll base = 29;

ll calc(string s)
{
    pre[0] = 0, p[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p[i] = p[i - 1] * base;
        pre[i] = pre[i - 1] * base + s[i] - 'a' + 1;
    }

    return pre[s.size() - 1];
}

ll get_ans(int l, int r)
{
    ll x = (pre[r] - pre[l - 1] * p[r - l + 1]);

    return x;
}

bool ok (int sz , int p , string &s)
{
    // cout << 1 << " " << min(sz , p) << endl;
    // cout << p + 1 << " " << min(int(s.size() - 1) , p + sz) << endl;
    // cout << get_ans(1 , min(sz , p)) << " " << get_ans(p + 1 , min(int(s.size() - 1) , p + sz)) << endl;
    // cout << "<<<----->>>\n";
    return (get_ans(1 , min(sz , p)) == get_ans(p + 1 , min(int(s.size() - 1) , p + sz)));
}

void solve()
{
    string s;
    cin >> s;

    s = '*' + s;
    calc(s);

    int q;
    cin >> q;

    while (q --)
    {
        int p;
        cin >> p;

        int l = 0 , r = p;

        while (l < r)
        {
            int mid = (l + r + 1) / 2;

            if (ok(mid , p , s))
                l = mid;
            else 
                r = mid - 1;
        }

        cout << l << endl;
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