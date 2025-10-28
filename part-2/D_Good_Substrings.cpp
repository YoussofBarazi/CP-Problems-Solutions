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

unordered_map <ll , int> freq;

vector<ll> pre(N), p(N);
ll base = 29;

ll calc(string s)
{
    pre[0] = 0, p[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p[i] = p[i - 1] * base;
        pre[i] = pre[i - 1] * base + s[i] - 'A' + 1;
    }

    return pre[s.size() - 1];
}

ll get_ans(int l, int r)
{
    ll x = (pre[r] - pre[l - 1] * p[r - l + 1]);

    return x;
}

void solve()
{
    int k;
    string s , t;
    cin >> s >> t >> k;

    s = '*' + s;

    calc(s);

    for (int i = 1 ; i < s.size() ; i ++)
    {
        int cnt = 0;

        for (int j = i ; j < s.size() ; j ++)
        {
            cnt += (t[s[j] - 'a'] == '0');

            if (cnt <= k)
            {    
                freq[get_ans(i , j)] ++;
            }
        }
    }

    cout << freq.size() << endl;
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