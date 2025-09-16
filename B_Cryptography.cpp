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
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);              \
    cout.tie(nullptr);
using namespace std;

const int N = 200009;

int n , r , m;

struct node {
    int a00 , a01 , a10 , a11;

    node()
    {
        a00 = 1 , a01 = 0 , a10 = 0 , a11 = 1;
    }

    node(int x , int y , int z , int w)
    {
        a00 = x , a01 = y , a10 = z , a11 = w;
    }
};

struct Segtree {
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector < node > seg;

    Segtree ()
    {
        seg.resize(n << 2 , node());
    }

    node merge(node L , node R)
    {
        node ans;

        ans.a00 = ((L.a00 * R.a00) + (L.a01 * R.a10)) % r;
        ans.a01 = ((L.a00 * R.a01) + (L.a01 * R.a11)) % r;
        ans.a10 = ((L.a10 * R.a00) + (L.a11 * R.a10)) % r;
        ans.a11 = ((L.a10 * R.a01) + (L.a11 * R.a11)) % r;

        return ans;
    }

    void update(int ndx , node a , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = a;
            return;
        }

        if (ndx <= mid)
            update(ndx , a , lc , l , mid);
        else 
            update(ndx , a , rc , mid + 1 , r);

        seg[id] = merge(seg[lc] , seg[rc]);
    }

    node query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return seg[id];
        
        if (l > R || L > r)
            return node();

        return merge(query(L , R , lc , l , mid) , query(L , R , rc , mid + 1 , r)); 
    }
};

void solve()
{
    scanf("%d%d%d" , &r , &n , &m);

    Segtree st;

    for (int i = 0 ; i < n ; i ++)
    {
        int a , b , c , d; 
        scanf("%d%d%d%d" , &a , &b , &c , &d);

        st.update(i + 1 , node(a , b , c , d));
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int l , r;
        scanf("%d%d" , &l , &r);

        node ans = st.query(l , r);

        printf("%d %d\n%d %d\n\n" , ans.a00 , ans.a01 , ans.a10 , ans.a11);
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