#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int n;

struct SegTree {

    #define lc (p << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)
    
    vi seg;

    SegTree() {
        seg.resize(n * 5, 0);
    }

    void update(int x, int ndx, int p = 1, int l = 1, int r = n) {

        if (l == r) {
            seg[p] = x;
            return ;
        } else if (ndx <= mid) {
            update(x, ndx, lc, l, mid);
        } else {
            update(x, ndx, rc, mid + 1, r);
        }

        seg[p] = seg[rc] | seg[lc];
    }
};

void solve()
{
    cin >> n;

    SegTree st;

    for (int i = 0 ; i < n ; i ++) {
        int x;
        cin >> x;

        st.update(x, i + 1);
    }

    set <int> s;
    for (int i = 1 ; i < n * 5 ; i ++) {
        if (st.seg[i] > 0) {
            s.insert(st.seg[i]);
        }
    } 

    for (auto x : s) {
        cout << x << ' ';
    } cout << endl;

    cout << s.size() << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}