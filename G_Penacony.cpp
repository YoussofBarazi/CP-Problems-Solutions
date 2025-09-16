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

int parent[N];

int find(int u)
{
    return parent[u] = (u == parent[u]) ? u : find(parent[u]);
}

void join(int u , int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return ;

    parent[v] = u;
}

int n , m;
struct SegmentTree
{
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <int> seg;

    SegmentTree ()
    {
        seg.resize((n << 2) + 100 , 1);
        build();
    }

    void build(int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
            return ;

        build(lc , l , mid);
        build(rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    void update(int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = 0;
            return ;
        }

        if (ndx <= mid)
            update(ndx , lc , l , mid);
        else 
            update(ndx , rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    int query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return seg[id];

        if (L > r || l > R)
            return 0;

        return query(L , R , lc , l , mid) + query(L , R , rc , mid + 1 , r);
    }
};

void solve()
{
    cin >> n >> m;

    for (int i = 1 ; i <= n ; i ++)
    {
        parent[i] = i;
    }

    SegmentTree st;

    int ans = 0;

    bool round = false;

    while (m --)
    {
        int u , v;
        cin >> u >> v;

        if (u > v)
            swap(u , v);

        int choice1 = st.query(u , v - 1);
        int choice2 = 0;

        // cout << st.query(2 , 2) << endl;

        if (v != n)
            choice2 += st.query(v , n - 1);
        if (u != 1)
            choice2 += st.query(1 , u - 1);
        if (!round)
            choice2 ++;

        if (choice1 < choice2)
        {
            u = find(u);
            v = find(v);

            while (u != v)
            {
                st.update(u);

                if (parent[u] == u)
                {
                    join(u + 1 , u);
                }

                u = find(u);
            }
        }
        else 
        {
            u = find(u);
            v = find(v);

            while (u != v) // u = 2 , v = 1
            {
                st.update(v);

                if (parent[v] == v)
                {
                    if (v == n) round = true;                       
                    join((v == n)? 1 : v + 1 , v);
                }

                v = find(v);
            }
        }

        ans += min(choice1 , choice2);
    }

    cout << ans << endl;
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