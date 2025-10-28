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

int n;

struct Node {
    ll val , add;

    Node()
    {
        val = 0 , add = 0;
    }
};

struct SegTree {
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector < Node > seg;

    SegTree()
    {
        seg.resize(4 * n , Node());
    }

    void update(int L , int R , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
        {
            seg[id].add += val;
            return ;
        }
        
        if (l > R || L > r)
            return ;

        update(L , R , val , lc , l , mid);
        update(L , R , val , rc , mid + 1 , r);

        seg[id].val = min(seg[lc].add + seg[lc].val , seg[rc].add + seg[rc].val);
    }

    ll query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return seg[id].val + seg[id].add;

        if (l > R || L > r)
            return 1e15;

        return min(query(L , R , lc , l , mid) + seg[id].add , query(L , R , rc , mid + 1 , r) + seg[id].add);
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