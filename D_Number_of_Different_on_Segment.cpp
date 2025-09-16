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

int n , m;

struct Segtree {
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <vector<bool>> seg;
    vector <bool> ans;

    Segtree()
    {
        seg.resize(4 * n , vector<bool>(41 , false));
    }

    void merge(int id)
    {
        for (int i = 0 ; i < 41 ; i ++)
        {
            seg[id][i] = seg[lc][i] | seg[rc][i];
        }
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = vector<bool> (41 , false);
            seg[id][val] = true;
            return ;
        }

        if(ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        merge(id);
    }

    void resize()
    {
        ans.assign(41 , false);
    }

    void query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
        {
            for (int i = 0 ; i < 41 ; i ++)
            {
                ans[i] = ans[i] | seg[id][i];
            }
            return;
        }

        if (l > R || L > r)
            return ;

        query(L , R , lc , l , mid);
        query(L , R , rc , mid + 1 , r);
    }

    int calc(int L , int R)
    {
        int cnt = 0;

        resize();
        query(L , R);

        for (int i = 0 ; i < 41 ; i ++)
            cnt += ans[i];

        return cnt;
    }
};

void solve()
{
    cin >> n >> m;

    Segtree st;

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        st.update(i + 1 , x);
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int t , x , y;
        cin >> t >> x >> y;

        if (t == 1)
        {
            cout << st.calc(x , y) << endl;
        }
        else 
        {
            st.update(x , y);
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