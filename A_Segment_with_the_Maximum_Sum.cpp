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

struct Node {

    ll sum , pref , suf , seg;

    Node()
    {
        sum = pref = suf = seg = 0;
    }

    Node(int v)
    {
        sum = pref = suf = seg = v;
    }
};

int n;

struct ST {

    #define lc (id << 1)
    #define rc ((id << 1) | 1)
    #define mid ((l + r) >> 1)

    vector <Node> seg;

    ST ()
    {
        Node t = Node();

        seg.resize(4 * n , t);
    }

    Node merge(int id)
    {
        Node a , b = seg[lc] , c = seg[rc];

        a.seg = max ({ b.seg , c.seg , b.suf + c.pref });
        a.pref = max({ b.pref , b.sum + c.pref });
        a.suf = max({ c.suf , b.suf + c.sum });
        a.sum = b.sum + c.sum;

        return a;
    }

    void update (int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = Node(val);
            return;
        }

        if (ndx <= mid)
            update (ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);
        
        seg[id] = merge(id);
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

    cout << max(0ll , st.seg[1].seg) << endl;

    while (m --)
    {
        int i , v;
        cin >> i >> v;

        st.update (++i , v);

        cout << max(0ll , st.seg[1].seg) << endl;
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