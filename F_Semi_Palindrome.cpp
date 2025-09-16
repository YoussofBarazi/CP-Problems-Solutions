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

vector<ll> pre1(N), pre2(N), p1(N), p2(N);
ll mod = 1e9 + 7;
ll base = 29;
 
int n; string s , t;


void calc()
{
    pre1[0] = pre2[0] = 0, p1[0] = p2[0] = 1;
    t = "";

    for (int i = 1; i < s.size(); i++)
    {
        p1[i] = p1[i - 1] * base;
        p1[i] %= mod;

        pre1[i] = pre1[i - 1] * base + s[i] - 'A' + 1;
        pre1[i] %= mod;

        t.push_back(s[i]);
    } 

    t.push_back('#');

    reverse(all(t));
    
    for (int i = 1; i < s.size(); i++)
    {
        p2[i] = p2[i - 1] * base;
        p2[i] %= mod;
    
        pre2[i] = pre2[i - 1] * base + t[i] - 'A' + 1;
        pre2[i] %= mod;
    } 
}
 
pair<ll, ll> get_hash(int l, int r)
{
    ll x = (pre1[r] - pre1[l - 1] * p1[r - l + 1] % mod + mod) % mod ;
    
    int t = r;

    r = n - l + 1 , l = n - t + 1; 
    
    ll y = (pre2[r] - pre2[l - 1] * p2[r - l + 1] % mod + mod) % mod ;
 
    return {x, y};
}


void update(int i , char c)
{
    pre1[i] -= (s[i] - 'a' + 1) * p1[i];
    pre1[i] += mod;
    pre1[i] += (c - 'a' + 1) * p1[i];
    pre1[i] %= mod;
    s[i] = c;

    i = n - i + 1;

    pre2[i] -= (t[i] - 'a' + 1) * p2[i];
    pre2[i] += mod;
    pre2[i] += (c - 'a' + 1) * p2[i];
    pre2[i] %= mod;
    t[i] = c;
}

void solve()
{
    cin >> n >> s;

    s = '#' + s;
    
    calc();

    int q;
    cin >> q;

    while (q --)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int i; char c;
            cin >> i >> c;

            update(i , c);
        }
        else 
        {
            int l , r;
            cin >> l >> r;

            int s = r - l + 1;

            pll t1 = get_hash(l , r);
            pll t2 = get_hash(l , r);

            cout << t1.F << " " << t2.S << endl; 
            
            if ((t1.first - t2.second + mod) % mod <= base)
            {
                cout << "YES" << endl;
            }
            else 
            {
                cout << "NO" << endl;
            }
        }
    }

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

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}