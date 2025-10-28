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
    int val , time;

    Node()
    {
        val = 0 , time = 0;
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

    void update(int L , int R , int val , int time , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
        {
            seg[id].time = time;
            seg[id].val = val;
            return ;
        }
        
        if (l > R || L > r)
            return ;

        update(L , R , val , time , lc , l , mid);
        update(L , R , val , time , rc , mid + 1 , r);
    }

    Node calc(Node a , Node b)
    {
        if (a.time < b.time)
            return b;
        
        return a;
    }

    Node query(int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
            return seg[id];

        if (ndx <= mid)
            return calc(query(ndx , lc , l , mid) , seg[id]);

        return calc(query(ndx , rc , mid + 1 , r) , seg[id]);
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

            st.update(l + 1 , r , v , i + 1);
        }
        else 
        {
            int ndx;
            cin >> ndx;

            cout << st.query(ndx + 1).val << endl;
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