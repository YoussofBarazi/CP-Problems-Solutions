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

struct Node 
{
    int mx , mn , sum;

    Node ()
    {
        mx = -1e9 , mn = 1e9 , sum = 0;
    }
    Node (int x)
    {
        mx = x , mn = x , sum = 1;
    }
};

int n;

struct SegTree
{
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <Node> seg;

    SegTree ()
    {
        seg.resize(n << 2 , Node());
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = Node(val);
            return;
        }

        seg[id] = Node();

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        seg[id].mn = min(seg[lc].mn , seg[rc].mn);
        seg[id].mx = max(seg[lc].mx , seg[rc].mx);
        seg[id].sum = seg[lc].sum + seg[rc].sum;
    }

    int query(int L , int R , int p , int id = 1 , int l = 1 , int r = n)
    {
        if (seg[id].mn > p)
            return 0;

        if (l > R || L > r)
            return 0;

        if (L <= l && r <= R && seg[id].mx <= p)
        {
            int ans = seg[id].sum;
            seg[id] = Node();
 
            return ans;
        }

        int ans = query(L , R , p , lc , l , mid) + query(L , R , p , rc , mid + 1 , r);
        
        if (!seg[lc].sum)
        {
            seg[id] = seg[rc];
        }
        
        if (!seg[rc].sum)
        {
            seg[id] = seg[lc];
        }

        return ans;
    }
};

void solve()
{
    int m;
    cin >> n >> m;

    SegTree st;

    while (m --)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int i , h;
            cin >> i >> h;

            st.update(i + 1 , h);
        }
        else
        {
            int l , r , p;
            cin >> l >> r >> p;

            cout << st.query(l + 1 , r , p) << endl;
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