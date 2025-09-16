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

const ll N = 200009 , mod = 1e9 + 7;

int n;

struct SegTree {

    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector < ll > seg;
    vector < ll > lazy;
    
    SegTree()
    {
        lazy.resize(n << 2 , -1);
        seg.resize(n << 2 , 0);
    }

    void push(int id , int l , int r)
    {
        if (lazy[id] == -1)
            return ;

        if (l != r)
        {
            lazy[lc] = lazy[id];
            lazy[rc] = lazy[id];
        }

        seg[id] = lazy[id] * (r - l + 1);
        
        lazy[id] = -1;
    }

    void update(int L , int R , ll val , int id = 1 , int l = 1 , int r = n)
    {
        push(id , l , r);

        if (L <= l && r <= R)
        {
            lazy[id] = val;
            push(id , l , r);
            return ;
        }
        
        if (l > R || L > r)
            return ;

        update(L , R , val , lc , l , mid);
        update(L , R , val , rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    ll query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        push(id , l , r);

        if (L <= l && r <= R)
            return seg[id];

        if (l > R || L > r)
            return 0;

        return query(L , R , lc , l , mid) + query(L , R , rc , mid + 1 , r);
    }
};

void solve()
{
    int m;
    cin >> n >> m;

    SegTree st;

    while (m --)
    {
        int t , l , r;
        cin >> t >> l >> r;

        l ++;

        if (t == 1)
        {
            int v;
            cin >> v;

            st.update(l , r , v);
        }
        else 
            cout << st.query(l , r) << endl;
    }
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

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}