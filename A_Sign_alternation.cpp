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

    vector <int> seg , mul;

    SegTree(int m)
    {
        seg.resize(4 * n , 0);

        for (int i = 0 ; i <= n ; i ++)
            mul.pb(m) , m *= -1;
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = val * mul[l];
            return ;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    int query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return seg[id];
        
        if (l > R || L > r)
            return 0;

        return query(L , R , lc , l , mid) + query(L , R , rc , mid + 1 , r);
    }
};

void solve()
{
    cin >> n;

    SegTree st1 = SegTree(1); // ndx % 2 == 1 ? - : +
    SegTree st0 = SegTree(-1);// ndx % 2 == 1 ? + : -

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        st1.update(i + 1 , x);
        st0.update(i + 1 , x);
    }

    int m;
    cin >> m;

    for (int i = 0 ; i < m ; i ++)
    {
        int t;
        cin >> t;

        if (t)
        {
            int l , r;
            cin >> l >> r;

            if (l % 2)
                cout << st0.query(l , r) << endl;
            else 
                cout << st1.query(l , r) << endl;
        }
        else 
        {
            int ndx , val;
            cin >> ndx >> val;

            st0.update(ndx , val);
            st1.update(ndx , val);
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