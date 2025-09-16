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
        seg[id] = seg[lc] + seg[rc];
    }

    void update(int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = !seg[id];
            return;
        }

        if (ndx <= mid)
            update(ndx , lc , l , mid);
        else 
            update(ndx , rc , mid + 1 , r);
        
        merge(id);
    }

    int query (int k , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
            return l - 1;

        if (seg[lc] < k)
            return query(k - seg[lc] , rc , mid + 1 , r);
        
        return query(k , lc , l , mid);
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

        if(x)
            st.update(i + 1);
    }

    while (m --)
    {
        int t , i;
        cin >> t >> i;

        if (t == 1)
            st.update(i + 1);
        else 
            cout << st.query(i + 1) << endl;
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