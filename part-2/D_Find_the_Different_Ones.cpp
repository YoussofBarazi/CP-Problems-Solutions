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

struct ST {
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <int> segmax , segmin;

    void init()
    {
        segmax.resize(4 * n , 0);
        segmin.resize(4 * n , 0);
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            segmax[id] = val;
            segmin[id] = val;
            return ;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        segmin[id] = min(segmin[lc] , segmin[rc]);
        segmax[id] = max(segmax[lc] , segmax[rc]);
    }

    int minq(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return segmin[id];

        if (l > R || L > r)
            return 1e9;

        return min(minq(L , R , lc , l , mid) , minq(L , R , rc , mid + 1 , r));
    }

    int maxq(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return segmax[id];

        if (l > R || L > r)
            return 0;

        return max(maxq(L , R , lc , l , mid) , maxq(L , R , rc , mid + 1 , r));
    }
};

void solve()
{
    cin >> n;

    map <int , set <int>> pos;
    
    ST st;
    st.init();

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        st.update(i + 1 , x);
        pos[x].insert(i + 1);
    }

    int q;
    cin >> q;

    while (q --)
    {
        int l , r;
        cin >> l >> r;

        int mn = st.minq(l , r) , mx = st.maxq(l , r);

        if (mn == mx)
            cout << "-1 -1" << endl;
        else 
        {
            cout << *pos[mn].lower_bound(l) << " " << *pos[mx].lower_bound(l) << endl;
        }
    }
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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