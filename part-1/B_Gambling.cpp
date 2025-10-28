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

int seg[2 * N];

void update(int p, int l, int r, int ndx, int val)
{
    if (l == r)
    {
        seg[p] += val;
        return;
    }

    int mid = (l + r) / 2;

    if (mid >= ndx)
        update(p * 2, l, mid, ndx, val);
    else
        update(p * 2 + 1, mid + 1, r, ndx, val);

    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
}

void solve()
{
    int n;
    cin >> n;

    vector < int > a(n);
    map < int, int > freq;
    
    for (auto &x : a)
    {
        cin >> x;

        freq[ x ] ++;
    }

    vector < pair < int , int > > max_freq;

    for (auto x : freq)
        max_freq.pb( { x.S , x.F } );

    sort( allr ( max_freq ) );

    int ans = 0 , mx = 0 , L = 1 , R = 1;

    for (int i = 0 ; i < min( ( int ) max_freq.size() , 500 ) ; i ++)
    {
        int x = max_freq[ i ].second;
        int cntx = 0 , cnt = 0;

        for (int i = 0 ; i < n ; i ++)
        {
            cntx += x == a[ i ];
            cnt  += x != a[ i ];

            if (cntx <= cnt)
                cntx = cnt = 0;
            
            if (cntx - cnt > mx)
            {
                ans = x;
                
                L = i - cntx - cnt + 2;
                R = i + 1;
                
                mx = cntx - cnt;
            }
        }
    }

    cout << ans << " " << L << " " << R << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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