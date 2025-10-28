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
        seg.resize(8 * n , 0);
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = (n << 1))
    {
        if (l == r)
        {
            seg[id] = val;
            return ;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    int query(int L , int R , int id = 1 , int l = 1 , int r = (n << 1))
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

    vector <int> left(n + 1 , 0) , right(n + 1 , 0) , a(2 * n) , ans(n + 1);

    SegTree st;

    for (int i = 0 ; i < n << 1 ; i ++)
    {
        int x;
        cin >> x;

        a[i] = x;

        if (left[x])
            right[x] = i + 1;
        else 
            left[x] = i + 1;
    }

    for (int i = 0 ; i < n << 1 ; i ++)
    {
        if (left[a[i]] == i + 1)
        {
            st.update(i + 1 , 1);
        }
        else
        {
            st.update(left[a[i]] , -1);
            st.update(right[a[i]] , 1);
            ans[a[i]] = st.query(left[a[i]] , right[a[i]]);
        }
    }

    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << " ";
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