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

struct SegTree {
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector < int > seg;

    SegTree()
    {
        seg.resize(4 * n , 0);
    }

    void update(int L , int R , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
        {
            seg[id] = max(val , seg[id]);
            return ;
        }
        
        if (l > R || L > r)
            return ;

        update(L , R , val , lc , l , mid);
        update(L , R , val , rc , mid + 1 , r);
    }

    int query(int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
            return seg[id];

        if (ndx <= mid)
            return max(seg[id] , query(ndx , lc , l , mid));

        return max(seg[id] , query(ndx , rc , mid + 1 , r));
    }
};

void solve()
{
    int m;
    cin >> n >> m;

    SegTree st;

    for (int i = 0 ; i < m ; i ++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int l , r , v;
            cin >> l >> r >> v;

            st.update(l + 1 , r , v);
        }
        else 
        {
            int ndx;
            cin >> ndx;

            cout << st.query(ndx + 1) << endl;
        }
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