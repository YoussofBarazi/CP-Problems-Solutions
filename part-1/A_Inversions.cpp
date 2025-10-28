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

    vector <int> seg;

    SegTree ()
    {
        seg.resize(n * 4 , 0);
    }

    void merge (int id)
    {
        seg[id] = seg[lc] + seg[rc];
    }

    void update(int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = 1;
            return ;
        }

        if (ndx <= mid)
            update (ndx , lc , l , mid);
        else 
            update (ndx , rc , mid + 1 , r);

        merge (id);
    }

    int query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return seg[id];

        if (l > R || r < L)
            return 0;
        
        return query(L , R , lc , l , mid) + query(L , R , rc , mid + 1 , r);
    }
};

void solve()
{
    cin >> n;

    SegTree st;

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        cout << st.query(x , n) << " " ;

        st.update(x);
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