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

const int N = 100009;

int n;

struct ST {

    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <int> seg;

    ST ()
    {
        seg.resize(4 * N);
    }

    void merge (int id)
    {
        seg[id] = max(seg[lc] , seg[rc]);
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
        
        merge(id);
    }

    int query (int ndx , int k , int id = 1 , int l = 1 , int r = n)
    {
        if (seg[id] < k)
            return 1e9;

        if (l == r)
            return l - 1;

        int q1 = 1e9 , q2 = 1e9;

        if (ndx <= mid && seg[lc] >= k)
            q1 = query(ndx , k , lc , l , mid);
        if (q1 == 1e9)
            q2 = query(ndx , k , rc , mid + 1 , r);

        return min(q1 , q2);
    }
};

void solve()
{
    int m;
    cin >> n >> m;

    ST st;

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        st.update(i + 1 , x);
    }

    while (m --)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int i , v;
            cin >> i >> v;

            st.update(i + 1 , v);
        }    
        else 
        {
            int x , l;
            cin >> x >> l;

            int ans = st.query(l + 1 , x);

            cout << ((ans == 1e9)? -1 : ans);
            cout << endl;
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