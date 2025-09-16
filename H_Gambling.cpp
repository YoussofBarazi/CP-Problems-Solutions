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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int n;

struct Node {

    ll sum , pref , suf , seg;
    int lsum , lpref , lsuf , lseg;
    int rsum , rpref , rsuf , rseg;

    Node()
    {
        sum = pref = suf = seg = 0;
    }

    Node(int v , int ndx)
    {
        sum = pref = suf = seg = v;
        lsum = lpref = lsuf = lseg = rsum = rpref = rsuf = rseg = ndx;
    }
};

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

        // a.seg = max ({ b.seg , c.seg , b.suf + c.pref });

        if (b.seg > c.seg)
            a.seg = b.seg , a.lseg = b.lseg , a.rseg = b.rseg;
        else 
            a.seg = c.seg , a.lseg = c.lseg , a.rseg = c.rseg;

        if (a.seg < b.suf + c.pref)
            a.seg = b.suf + c.pref , a.lseg = b.lsuf , a.rseg = c.rpref;

        // a.pref = max({ b.pref , b.sum + c.pref });
        
        if (b.pref > b.sum + c.pref)
            a.pref = b.pref , a.lpref = b.lpref , a.rpref = b.rpref;
        else 
            a.pref = b.sum + c.pref , a.lpref = b.lsum , a.rpref = c.rpref;

        // a.suf = max({ c.suf , b.suf + c.sum });

        if (c.suf > b.suf + c.sum)
            a.suf = c.suf , a.lsuf = c.lsuf , a.rsuf = c.rsuf;
        else 
            a.suf = b.suf + c.sum , a.lsuf = b.lsuf , a.rsuf = c.rsum;

        a.sum = b.sum + c.sum;
        
        a.lsum = b.lsum , a.rsum = c.rsum;

        return a;
    }

    void update (int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = Node(val , ndx);
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
    cin >> n;

    vector <int> a(n);
    map <int , vi> ndx;
    ST st;

    for (int i = 0 ; i < n ; i ++)
    {    
        cin >> a[i];

        ndx[a[i]].push_back(i + 1);

        st.update(i + 1 , -1);
    }

    int ans = a[0] , l = 1 , r = 1 , mx = 1;

    for (auto x : ndx)
    {
        for (auto i : x.S)
        {
            st.update(i , 1);
        }   

        if (st.seg[1].seg > mx)
            mx = st.seg[1].seg , l = st.seg[1].lseg , r = st.seg[1].rseg , ans = x.F;

        for (auto i : x.S)
        {
            st.update(i , -1);
        }
    }

    cout << ans << " " << l << " " << r << endl;
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