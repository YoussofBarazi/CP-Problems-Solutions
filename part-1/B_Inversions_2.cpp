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

    SegTree()
    {
        seg.resize(4 * n , 0);
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = val;
            return;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    int query(int k , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
            return l;
        
        if (seg[lc] < k)
            return query(k - seg[lc] , rc , mid + 1 , r);
        
        return query(k , lc , l , mid);
    }
};

void solve()
{
    cin >> n;

    vector <int> a(n);
    for (auto &x : a)
        cin >> x;

    SegTree st;

    for (int i = 1 ; i <= n ; i ++)
        st.update(i , 1);

    vector <int> ans(n);

    for (int i = n - 1 ; i >= 0 ; i --)
    {   
        int x = st.query(st.seg[1] - a[i]);

        st.update(x , 0);

        ans[i] = x;
    }

    for (auto x : ans)
        cout << x << " " ;
    cout << endl;
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